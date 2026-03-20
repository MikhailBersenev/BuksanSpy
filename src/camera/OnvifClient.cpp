#include "OnvifClient.h"

#include <QAuthenticator>
#include <QCryptographicHash>
#include <QDateTime>
#include <QEventLoop>
#include <QElapsedTimer>
#include <QHostAddress>
#include <QNetworkAccessManager>
#include <QNetworkDatagram>
#include <QNetworkProxy>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QRegularExpression>
#include <QThread>
#include <QTimer>
#include <QUdpSocket>
#include <QUuid>
#include <QUrl>
#include <QXmlStreamReader>
#include <QRandomGenerator>
#include <QSet>
#include <QSslError>
#include <QtGlobal>
#include <QtConcurrent/QtConcurrentRun>

#include "Loggerd.h"

namespace {
constexpr quint16 kWsDiscoveryPort = 3702;
const char *kWsDiscoveryAddress = "239.255.255.250";

/** Masks password in URL for logs (username kept for easier debugging). */
QString urlForLog(const QString &urlStr)
{
    QUrl u(urlStr);
    if (!u.isValid() || urlStr.isEmpty()) {
        return urlStr;
    }
    if (!u.password().isEmpty()) {
        u.setPassword(QStringLiteral("***"));
    }
    return u.toString();
}

QString previewXml(const QByteArray &xml, int maxLen = 400)
{
    QString s = QString::fromUtf8(xml);
    s.replace(QLatin1Char('\n'), QLatin1Char(' '));
    s.replace(QLatin1Char('\r'), QLatin1Char(' '));
    if (s.size() > maxLen) {
        s.truncate(maxLen);
        s += QStringLiteral("...");
    }
    return s;
}

/** SOAP 1.1/1.2 fault text (faultstring or s:Text under Reason). */
QString extractSoapFault(const QByteArray &data)
{
    const QString t = QString::fromUtf8(data);
    if (!t.contains(QStringLiteral("Fault"), Qt::CaseInsensitive)) {
        return {};
    }
    static const QRegularExpression rxFaultString(
        QStringLiteral("faultstring[^>]*>([^<]+)</"),
        QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch m = rxFaultString.match(t);
    if (m.hasMatch()) {
        return m.captured(1).trimmed();
    }
    static const QRegularExpression rxText(QStringLiteral("<[^:>]*:?Text[^>]*>([^<]+)</[^:>]*:?Text>"));
    m = rxText.match(t);
    if (m.hasMatch()) {
        return m.captured(1).trimmed();
    }
    return {};
}
} // namespace

OnvifClient::OnvifClient(QObject *parent)
    : QObject(parent)
    , m_requestTimeoutMs(8000)
    , m_discoveryTimeoutMs(3000)
{
}

QVector<OnvifCamera> OnvifClient::discoverCameras()
{
    QVector<OnvifCamera> cameras;
    const QVector<QString> deviceUrls = discoverDeviceUrls();
    for (const QString &deviceUrl : deviceUrls) {
        OnvifCamera camera = getCameraCapabilities(deviceUrl);
        if (camera.name.isEmpty()) {
            camera.name = deviceUrl;
        }
        cameras.push_back(camera);
    }
    LOG_INFO_MSG((QStringLiteral("OnvifClient discovered cameras: ") + QString::number(cameras.size())).toStdString());
    return cameras;
}

OnvifCamera OnvifClient::getCameraCapabilities(const QString &deviceUrl)
{
    OnvifCamera camera;
    camera.name = deviceUrl;

    {
        QMutexLocker locker(&m_mutex);
        if (m_username.trimmed().isEmpty() && m_password.isEmpty()) {
            LOG_INFO_MSG(
                "ONVIF: username/password empty — GetDeviceInformation/GetCapabilities often need HTTP Basic "
                "(e.g. Hikvision); set ONVIF credentials in the dialog.");
        } else if (m_username.trimmed().isEmpty() && !m_password.isEmpty()) {
            LOG_INFO_MSG(
                "ONVIF: password set without username — WS-Security header is not built; enter username.");
        }
    }

    const QString serviceUrl = resolveDeviceServiceUrl(deviceUrl);
    if (serviceUrl.isEmpty()) {
        publishError(QStringLiteral("Invalid device URL: %1").arg(deviceUrl));
        return camera;
    }
    LOG_INFO_MSG(
        (QStringLiteral("ONVIF getCameraCapabilities: deviceService=") + urlForLog(serviceUrl)).toStdString());

    const QString getInfoInner =
        QStringLiteral("<tds:GetDeviceInformation xmlns:tds=\"http://www.onvif.org/ver10/device/wsdl\"/>");

    QString errorText;
    const QByteArray infoReply = sendSoapRequest(
        QUrl(serviceUrl),
        QStringLiteral("http://www.onvif.org/ver10/device/wsdl/GetDeviceInformation"),
        getInfoInner,
        &errorText);

    if (!infoReply.isEmpty()) {
        camera.manufacturer = parseFirstTagText(infoReply, QStringLiteral("Manufacturer"));
        camera.model = parseFirstTagText(infoReply, QStringLiteral("Model"));
        camera.firmwareVersion = parseFirstTagText(infoReply, QStringLiteral("FirmwareVersion"));
        camera.hardwareId = parseFirstTagText(infoReply, QStringLiteral("HardwareId"));
        if (!camera.model.isEmpty()) {
            camera.name = camera.model;
        }
    } else if (!errorText.isEmpty()) {
        publishError(QStringLiteral("GetDeviceInformation failed for %1: %2").arg(deviceUrl, errorText));
    }
    if (!camera.manufacturer.isEmpty() || !camera.model.isEmpty()) {
        LOG_INFO_MSG((QStringLiteral("ONVIF GetDeviceInformation: manufacturer=\"%1\" model=\"%2\"")
                          .arg(camera.manufacturer, camera.model))
                         .toStdString());
    }

    const QString mediaServiceUrl = getMediaServiceUrl(serviceUrl);
    if (mediaServiceUrl.isEmpty()) {
        LOG_INFO_MSG("ONVIF: Media service URL empty — GetStreamUri skipped (check GetCapabilities(Media)).");
    } else {
        LOG_INFO_MSG((QStringLiteral("ONVIF Media XAddr: ") + urlForLog(mediaServiceUrl)).toStdString());
        const QString token = getFirstProfileToken(mediaServiceUrl);
        if (token.isEmpty()) {
            LOG_INFO_MSG("ONVIF: no ProfileToken from GetProfiles — RTSP not requested.");
        } else {
            LOG_INFO_MSG((QStringLiteral("ONVIF: first ProfileToken=\"") + token + QStringLiteral("\""))
                             .toStdString());
            camera.rtspUrl = getRtspUrl(serviceUrl, token);
            if (camera.rtspUrl.isEmpty()) {
                LOG_INFO_MSG(
                    "ONVIF: GetStreamUri returned empty Uri — check profile/permissions or enter RTSP manually.");
            } else {
                LOG_INFO_MSG((QStringLiteral("ONVIF: final RTSP (password masked): ") + urlForLog(camera.rtspUrl))
                                 .toStdString());
            }
        }
    }

    const QString getCapsInner =
        QStringLiteral("<tds:GetCapabilities xmlns:tds=\"http://www.onvif.org/ver10/device/wsdl\">"
                       "<tds:Category>All</tds:Category>"
                       "</tds:GetCapabilities>");

    const QByteArray capsReply = sendSoapRequest(
        QUrl(serviceUrl),
        QStringLiteral("http://www.onvif.org/ver10/device/wsdl/GetCapabilities"),
        getCapsInner,
        &errorText);

    if (!capsReply.isEmpty()) {
        const QString ptzXAddr = parseFirstTagText(capsReply, QStringLiteral("PTZ"));
        camera.ptzSupported = !ptzXAddr.isEmpty() || capsReply.contains("PTZ");
    }

    emit capabilitiesReceived(deviceUrl, camera);
    return camera;
}

QString OnvifClient::getRtspUrl(const QString &deviceUrl, const QString &profileToken)
{
    if (profileToken.isEmpty()) {
        publishError(QStringLiteral("Profile token is empty for %1").arg(deviceUrl));
        return QString();
    }

    const QString mediaServiceUrl = getMediaServiceUrl(deviceUrl);
    if (mediaServiceUrl.isEmpty()) {
        publishError(QStringLiteral("Unable to resolve Media service URL for %1").arg(deviceUrl));
        return QString();
    }

    LOG_INFO_MSG((QStringLiteral("ONVIF GetStreamUri: device=") + urlForLog(deviceUrl) + QStringLiteral(" media=")
                  + urlForLog(mediaServiceUrl) + QStringLiteral(" ProfileToken=\"") + profileToken
                  + QStringLiteral("\""))
                     .toStdString());

    const QString bodyInner = QStringLiteral(
        "<trt:GetStreamUri xmlns:trt=\"http://www.onvif.org/ver10/media/wsdl\">"
        "<trt:StreamSetup>"
        "<tt:Stream xmlns:tt=\"http://www.onvif.org/ver10/schema\">RTP-Unicast</tt:Stream>"
        "<tt:Transport xmlns:tt=\"http://www.onvif.org/ver10/schema\">"
        "<tt:Protocol>RTSP</tt:Protocol>"
        "</tt:Transport>"
        "</trt:StreamSetup>"
        "<trt:ProfileToken>%1</trt:ProfileToken>"
        "</trt:GetStreamUri>")
                             .arg(profileToken.toHtmlEscaped());

    QString errorText;
    const QByteArray reply = sendSoapRequest(
        QUrl(mediaServiceUrl),
        QStringLiteral("http://www.onvif.org/ver10/media/wsdl/GetStreamUri"),
        bodyInner,
        &errorText);

    if (reply.isEmpty()) {
        publishError(QStringLiteral("GetStreamUri failed (media %1, device %2): %3")
                         .arg(mediaServiceUrl, deviceUrl, errorText));
        return QString();
    }

    QString uri = parseFirstTagText(reply, QStringLiteral("Uri"));
    if (uri.isEmpty()) {
        const QRegularExpression rx(QStringLiteral("<[^:>]*:?Uri>([^<]+)</[^:>]*:?Uri>"));
        const QRegularExpressionMatch match = rx.match(QString::fromUtf8(reply));
        if (match.hasMatch()) {
            uri = match.captured(1);
        }
    }

    if (uri.isEmpty()) {
        LOG_INFO_MSG(
            (QStringLiteral("ONVIF GetStreamUri: no Uri element in response, XML preview: ") + previewXml(reply))
                .toStdString());
    } else {
        LOG_INFO_MSG(
            (QStringLiteral("ONVIF GetStreamUri: parsed Uri=") + urlForLog(uri)).toStdString());
    }

    emit rtspUrlReceived(deviceUrl, profileToken, uri);
    return uri;
}

QFuture<QVector<OnvifCamera>> OnvifClient::discoverCamerasAsync()
{
    return QtConcurrent::run([this]() {
        const QVector<OnvifCamera> cameras = discoverCameras();
        emit camerasDiscovered(cameras);
        return cameras;
    });
}

QFuture<OnvifCamera> OnvifClient::getCameraCapabilitiesAsync(const QString &deviceUrl)
{
    return QtConcurrent::run([this, deviceUrl]() { return getCameraCapabilities(deviceUrl); });
}

QFuture<QString> OnvifClient::getRtspUrlAsync(const QString &deviceUrl, const QString &profileToken)
{
    return QtConcurrent::run([this, deviceUrl, profileToken]() { return getRtspUrl(deviceUrl, profileToken); });
}

OnvifClient::HostProbeInput OnvifClient::parseHostForOnvif(const QString &hostOrUrl)
{
    HostProbeInput out;
    const QString s = hostOrUrl.trimmed();
    if (s.isEmpty()) {
        return out;
    }
    if (s.contains(QStringLiteral("://"))) {
        const QUrl u = QUrl::fromUserInput(s);
        if (u.isValid() && !u.host().isEmpty()) {
            out.host = u.host();
            if (u.port() > 0) {
                out.explicitPort = u.port();
            }
            return out;
        }
    }
    const int colon = s.lastIndexOf(QLatin1Char(':'));
    if (colon > 0) {
        const QString right = s.mid(colon + 1);
        bool ok = false;
        const int p = right.toInt(&ok);
        if (ok && p >= 1 && p <= 65535) {
            const QString left = s.left(colon);
            if (!left.contains(QLatin1Char(':'))) {
                out.host = left;
                out.explicitPort = p;
                return out;
            }
        }
    }
    out.host = s;
    return out;
}

QVector<QUrl> OnvifClient::buildCandidateOnvifDeviceUrls(const QString &host, int explicitPort) const
{
    QVector<QUrl> out;
    QSet<QString> seen;
    const QString path = QStringLiteral("/onvif/device_service");

    auto add = [&](const QUrl &u) {
        if (!u.isValid() || u.host().isEmpty()) {
            return;
        }
        const QString key = u.toString(QUrl::RemoveUserInfo);
        if (seen.contains(key)) {
            return;
        }
        seen.insert(key);
        out.push_back(u);
    };

    const QString h = host.trimmed();
    if (h.isEmpty()) {
        return out;
    }

    if (explicitPort >= 1 && explicitPort <= 65535) {
        {
            QUrl u;
            u.setScheme(QStringLiteral("http"));
            u.setHost(h);
            u.setPort(explicitPort);
            u.setPath(path);
            add(u);
        }
        {
            QUrl u;
            u.setScheme(QStringLiteral("https"));
            u.setHost(h);
            u.setPort(explicitPort);
            u.setPath(path);
            add(u);
        }
    }

    /* Hikvision/Dahua often use 80, 8080, 8000 — common web ports first. */
    const QList<std::pair<QString, int>> httpPorts = {
        {QStringLiteral("http"), 80},
        {QStringLiteral("http"), 8080},
        {QStringLiteral("http"), 8000},
        {QStringLiteral("http"), 81},
        {QStringLiteral("http"), 8088},
        {QStringLiteral("http"), 8888},
        {QStringLiteral("http"), 8880},
        {QStringLiteral("http"), 8899},
        {QStringLiteral("http"), 6688},
        {QStringLiteral("http"), 9000},
        {QStringLiteral("http"), 10080},
    };
    const QList<std::pair<QString, int>> httpsPorts = {
        {QStringLiteral("https"), 443},
        {QStringLiteral("https"), 8443},
    };

    for (const auto &sp : httpPorts) {
        if (explicitPort >= 1 && sp.second == explicitPort) {
            continue;
        }
        QUrl u;
        u.setScheme(sp.first);
        u.setHost(h);
        u.setPort(sp.second);
        u.setPath(path);
        add(u);
    }
    for (const auto &sp : httpsPorts) {
        if (explicitPort >= 1 && sp.second == explicitPort) {
            continue;
        }
        QUrl u;
        u.setScheme(sp.first);
        u.setHost(h);
        u.setPort(sp.second);
        u.setPath(path);
        add(u);
    }

    {
        QUrl u;
        u.setScheme(QStringLiteral("http"));
        u.setHost(h);
        u.setPath(path);
        add(u);
    }
    {
        QUrl u;
        u.setScheme(QStringLiteral("https"));
        u.setHost(h);
        u.setPath(path);
        add(u);
    }

    return out;
}

QString OnvifClient::findDeviceServiceUrlByHost(const QString &hostOrUrl)
{
    const QString trimmed = hostOrUrl.trimmed();
    if (trimmed.isEmpty()) {
        publishError(QStringLiteral("Empty IP or host"));
        return {};
    }

    QVector<QUrl> candidates;
    QSet<QString> seen;

    auto addCandidate = [&](const QUrl &u) {
        if (!u.isValid() || u.host().isEmpty()) {
            return;
        }
        const QString key = u.toString(QUrl::RemoveUserInfo);
        if (seen.contains(key)) {
            return;
        }
        seen.insert(key);
        candidates.push_back(u);
    };

    if (trimmed.contains(QStringLiteral("://"))) {
        const QUrl userUrl = QUrl::fromUserInput(trimmed);
        if (userUrl.isValid() && !userUrl.host().isEmpty()) {
            addCandidate(userUrl);
        }
    }

    const HostProbeInput probe = parseHostForOnvif(trimmed);
    if (!probe.host.isEmpty()) {
        for (const QUrl &u : buildCandidateOnvifDeviceUrls(probe.host, probe.explicitPort)) {
            addCandidate(u);
        }
    }

    if (candidates.isEmpty()) {
        publishError(QStringLiteral("Invalid IP or host: %1").arg(trimmed));
        return {};
    }

    /* Many devices require auth for GetDeviceInformation; GetSystemDateAndTime is often open. */
    const QString probeDateInner =
        QStringLiteral("<tds:GetSystemDateAndTime xmlns:tds=\"http://www.onvif.org/ver10/device/wsdl\"/>");
    const QString probeDateAction =
        QStringLiteral("http://www.onvif.org/ver10/device/wsdl/GetSystemDateAndTime");
    const QString probeInfoInner =
        QStringLiteral("<tds:GetDeviceInformation xmlns:tds=\"http://www.onvif.org/ver10/device/wsdl\"/>");
    const QString probeInfoAction =
        QStringLiteral("http://www.onvif.org/ver10/device/wsdl/GetDeviceInformation");

    bool hasCreds = false;
    {
        QMutexLocker locker(&m_mutex);
        hasCreds = !m_username.trimmed().isEmpty() || !m_password.isEmpty();
    }

    QString lastErr;
    int connectionRefusedCount = 0;
    for (const QUrl &u : std::as_const(candidates)) {
        QString err;
        QByteArray reply;
        /* With credentials, many devices answer GetDeviceInformation first; anonymous probe is GetSystemDateAndTime. */
        if (hasCreds) {
            reply = sendSoapRequest(u, probeInfoAction, probeInfoInner, &err);
            if (reply.isEmpty()) {
                reply = sendSoapRequest(u, probeDateAction, probeDateInner, &err);
            }
        } else {
            reply = sendSoapRequest(u, probeDateAction, probeDateInner, &err);
            if (reply.isEmpty()) {
                reply = sendSoapRequest(u, probeInfoAction, probeInfoInner, &err);
            }
        }
        if (!reply.isEmpty()) {
            LOG_INFO_MSG((QStringLiteral("ONVIF Device Service found: ") + u.toString()).toStdString());
            return u.toString();
        }
        if (!err.isEmpty()) {
            lastErr = err;
            if (err.contains(QLatin1String("Connection refused"), Qt::CaseInsensitive)) {
                ++connectionRefusedCount;
            }
        }
    }

    QString hint;
    if (lastErr.isEmpty()) {
        hint = QStringLiteral("Check IP, port (e.g. 192.168.x.x:8080), ONVIF credentials, and that the service "
                                "is enabled.");
    } else if (connectionRefusedCount > 0
               && lastErr.contains(QLatin1String("Connection refused"), Qt::CaseInsensitive)) {
        hint = QStringLiteral(
                   "Last error: %1. Connection refused means nothing is listening for HTTP(S) on that TCP port. "
                   "RTSP (port 554) may still work while web/ONVIF HTTP is off — enable HTTP/HTTPS and ONVIF in "
                   "the camera web UI, or set the port explicitly: 192.168.x.x:8080 or "
                   "http://192.168.x.x:8000/onvif/device_service. Disable system HTTP proxy for LAN or check "
                   "firewall.")
                   .arg(lastErr);
    } else {
        hint = QStringLiteral("Last error: %1. Try host:port or full device_service URL, HTTPS, and credentials.")
                   .arg(lastErr);
    }
    const QString msg =
        QStringLiteral("ONVIF Device Service not found for: %1. %2").arg(trimmed, hint);
    LOG_INFO_MSG(msg.toStdString());
    emit errorOccurred(msg);
    return {};
}

OnvifCamera OnvifClient::discoverCameraByHost(const QString &hostOrUrl)
{
    const QString url = findDeviceServiceUrlByHost(hostOrUrl);
    if (url.isEmpty()) {
        return {};
    }
    return getCameraCapabilities(url);
}

QFuture<OnvifCamera> OnvifClient::discoverCameraByHostAsync(const QString &hostOrUrl)
{
    return QtConcurrent::run([this, hostOrUrl]() { return discoverCameraByHost(hostOrUrl); });
}

void OnvifClient::setRequestTimeoutMs(int timeoutMs)
{
    QMutexLocker locker(&m_mutex);
    m_requestTimeoutMs = qMax(100, timeoutMs);
}

void OnvifClient::setDiscoveryTimeoutMs(int timeoutMs)
{
    QMutexLocker locker(&m_mutex);
    m_discoveryTimeoutMs = qMax(200, timeoutMs);
}

void OnvifClient::setCredentials(const QString &username, const QString &password)
{
    QMutexLocker locker(&m_mutex);
    m_username = username;
    m_password = password;
}

QString OnvifClient::username() const
{
    QMutexLocker locker(&m_mutex);
    return m_username;
}

QString OnvifClient::password() const
{
    QMutexLocker locker(&m_mutex);
    return m_password;
}

QString OnvifClient::buildSoapEnvelope(const QString &bodyInnerXml) const
{
    QString securityHeader;
    {
        QMutexLocker locker(&m_mutex);
        if (!m_username.isEmpty()) {
            QByteArray nonceBytes;
            nonceBytes.resize(16);
            for (int i = 0; i < nonceBytes.size(); ++i) {
                nonceBytes[i] = static_cast<char>(QRandomGenerator::global()->bounded(256));
            }
            const QString created = QDateTime::currentDateTimeUtc().toString(Qt::ISODateWithMs);
            const QByteArray createdBytes = created.toUtf8();
            const QByteArray passwordBytes = m_password.toUtf8();
            const QByteArray sha1Input = nonceBytes + createdBytes + passwordBytes;
            const QByteArray digest = QCryptographicHash::hash(sha1Input, QCryptographicHash::Sha1);
            const QString passwordDigest = QString::fromLatin1(digest.toBase64());
            const QString nonceB64 = QString::fromLatin1(nonceBytes.toBase64());

            securityHeader = QStringLiteral(
                "<s:Header>"
                "<wsse:Security "
                "xmlns:wsse=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\" "
                "xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">"
                "<wsse:UsernameToken>"
                "<wsse:Username>%1</wsse:Username>"
                "<wsse:Password "
                "Type=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-username-token-profile-1.0#PasswordDigest\">"
                "%2</wsse:Password>"
                "<wsse:Nonce "
                "EncodingType=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-soap-message-security-1.0#Base64Binary\">"
                "%3</wsse:Nonce>"
                "<wsu:Created>%4</wsu:Created>"
                "</wsse:UsernameToken>"
                "</wsse:Security>"
                "</s:Header>")
                                   .arg(m_username.toHtmlEscaped(),
                                        passwordDigest,
                                        nonceB64,
                                        created.toHtmlEscaped());
        }
    }

    return QStringLiteral(
               "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
               "<s:Envelope xmlns:s=\"http://www.w3.org/2003/05/soap-envelope\">")
           + securityHeader + QStringLiteral("<s:Body>") + bodyInnerXml + QStringLiteral("</s:Body></s:Envelope>");
}

void OnvifClient::applyHttpAuthentication(QNetworkRequest &request) const
{
    QString user;
    QString pass;
    {
        QMutexLocker locker(&m_mutex);
        user = m_username;
        pass = m_password;
    }
    if (user.isEmpty() && pass.isEmpty()) {
        return;
    }
    /* QByteArray concat — correct for passwords with ':' and special chars before Base64 */
    const QByteArray token = (user.toUtf8() + QByteArrayLiteral(":") + pass.toUtf8()).toBase64();
    request.setRawHeader("Authorization", QByteArrayLiteral("Basic ") + token);
}

QString OnvifClient::makeDiscoveryProbeMessage() const
{
    const QString messageId = QStringLiteral("uuid:%1").arg(QUuid::createUuid().toString(QUuid::WithoutBraces));
    return QStringLiteral(
               "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
               "<e:Envelope xmlns:e=\"http://www.w3.org/2003/05/soap-envelope\" "
               "xmlns:w=\"http://schemas.xmlsoap.org/ws/2004/08/addressing\" "
               "xmlns:d=\"http://schemas.xmlsoap.org/ws/2005/04/discovery\" "
               "xmlns:dn=\"http://www.onvif.org/ver10/network/wsdl\">"
               "<e:Header>"
               "<w:MessageID>%1</w:MessageID>"
               "<w:To>urn:schemas-xmlsoap-org:ws:2005:04:discovery</w:To>"
               "<w:Action>http://schemas.xmlsoap.org/ws/2005/04/discovery/Probe</w:Action>"
               "</e:Header>"
               "<e:Body>"
               "<d:Probe>"
               "<d:Types>dn:NetworkVideoTransmitter</d:Types>"
               "</d:Probe>"
               "</e:Body>"
               "</e:Envelope>")
        .arg(messageId);
}

QVector<QString> OnvifClient::discoverDeviceUrls()
{
    QVector<QString> deviceUrls;
    QUdpSocket socket;

    if (!socket.bind(QHostAddress::AnyIPv4, 0, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint)) {
        publishError(QStringLiteral("WS-Discovery bind failed: %1").arg(socket.errorString()));
        return deviceUrls;
    }

    const QByteArray probe = makeDiscoveryProbeMessage().toUtf8();
    const qint64 sent = socket.writeDatagram(probe, QHostAddress(QString::fromLatin1(kWsDiscoveryAddress)), kWsDiscoveryPort);
    if (sent < 0) {
        publishError(QStringLiteral("WS-Discovery probe send failed: %1").arg(socket.errorString()));
        return deviceUrls;
    }

    int discoveryTimeoutMs = 3000;
    {
        QMutexLocker locker(&m_mutex);
        discoveryTimeoutMs = m_discoveryTimeoutMs;
    }

    QElapsedTimer timer;
    timer.start();
    while (timer.elapsed() < discoveryTimeoutMs) {
        const int waitMs = qMin(250, discoveryTimeoutMs - static_cast<int>(timer.elapsed()));
        if (!socket.waitForReadyRead(waitMs)) {
            continue;
        }
        while (socket.hasPendingDatagrams()) {
            const QNetworkDatagram datagram = socket.receiveDatagram();
            const QByteArray payload = datagram.data();
            const QVector<QString> xAddrs = parseTagValues(payload, QStringLiteral("XAddrs"));
            for (const QString &xAddrEntry : xAddrs) {
                const QStringList parts = xAddrEntry.split(' ', Qt::SkipEmptyParts);
                for (const QString &url : parts) {
                    if (!deviceUrls.contains(url)) {
                        deviceUrls.push_back(url);
                    }
                }
            }
        }
    }

    return deviceUrls;
}

QByteArray OnvifClient::sendSoapRequest(
    const QUrl &url,
    const QString &soapAction,
    const QString &bodyInnerXml,
    QString *errorText)
{
    if (!url.isValid() || url.isEmpty()) {
        if (errorText) {
            *errorText = QStringLiteral("Invalid URL");
        }
        return {};
    }

    const QString envelope = buildSoapEnvelope(bodyInnerXml);

    QNetworkAccessManager manager;
    /* Avoid global HTTP(S) proxy hijacking LAN requests to 192.168.x.x (Connection refused). */
    QNetworkProxy noProxy;
    noProxy.setType(QNetworkProxy::NoProxy);
    manager.setProxy(noProxy);

    QObject::connect(
        &manager,
        &QNetworkAccessManager::authenticationRequired,
        &manager,
        [this](QNetworkReply *reply, QAuthenticator *authenticator) {
            Q_UNUSED(reply);
            QString user;
            QString pass;
            {
                QMutexLocker locker(&m_mutex);
                user = m_username;
                pass = m_password;
            }
            if (!user.isEmpty() || !pass.isEmpty()) {
                authenticator->setUser(user);
                authenticator->setPassword(pass);
            }
        });

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QStringLiteral("application/soap+xml; charset=utf-8"));
    /* Unquoted SOAPAction — some firmware rejects quoted values; others want Content-Type action= (not used here). */
    request.setRawHeader("SOAPAction", soapAction.toUtf8());
    request.setRawHeader("User-Agent", QByteArrayLiteral("BuksanSpy/1.0 (ONVIF; Qt)"));
    applyHttpAuthentication(request);

    QNetworkReply *reply = manager.post(request, envelope.toUtf8());

#ifndef QT_NO_SSL
    /* Qt 5 / Qt 6.0–6.8: QNetworkReply::sslErrors; 6.2+ also has sslErrorsOccurred (not always in headers). */
    QObject::connect(reply, &QNetworkReply::sslErrors, reply, [reply](const QList<QSslError> &errors) {
        Q_UNUSED(errors);
        reply->ignoreSslErrors();
    });
#endif

    int requestTimeoutMs = 4000;
    {
        QMutexLocker locker(&m_mutex);
        requestTimeoutMs = m_requestTimeoutMs;
    }

    QEventLoop loop;
    QTimer timeoutTimer;
    timeoutTimer.setSingleShot(true);

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    connect(&timeoutTimer, &QTimer::timeout, &loop, &QEventLoop::quit);
    timeoutTimer.start(requestTimeoutMs);
    loop.exec();

    if (timeoutTimer.isActive()) {
        timeoutTimer.stop();
    } else {
        reply->abort();
        if (errorText) {
            *errorText = QStringLiteral("Request timeout");
        }
        reply->deleteLater();
        return {};
    }

    const QNetworkReply::NetworkError netErr = reply->error();
    const QString replyErrorString = reply->errorString();
    const QByteArray data = reply->readAll();
    reply->deleteLater();

    if (netErr != QNetworkReply::NoError) {
        if (errorText) {
            QString err = replyErrorString;
            const QString faultBody = extractSoapFault(data);
            if (!faultBody.isEmpty()) {
                err = faultBody;
            }
            const bool authHint = netErr == QNetworkReply::AuthenticationRequiredError
                                  || err.contains(QLatin1String("authentication"), Qt::CaseInsensitive);
            if (authHint) {
                QString user;
                QString pass;
                {
                    QMutexLocker locker(&m_mutex);
                    user = m_username;
                    pass = m_password;
                }
                if (user.isEmpty() && pass.isEmpty()) {
                    err += QStringLiteral(" — set ONVIF username and password in the dialog (HTTP Basic + WS-Security).");
                } else {
                    err += QStringLiteral(" — check username/password; device may require Digest (see web UI).");
                }
            }
            *errorText = err;
        }
        return {};
    }

    QString faultString = parseFirstTagText(data, QStringLiteral("faultstring"));
    if (faultString.isEmpty()) {
        faultString = extractSoapFault(data);
    }
    if (!faultString.isEmpty()) {
        if (errorText) {
            *errorText = faultString;
        }
        return {};
    }

    return data;
}

QString OnvifClient::parseFirstTagText(const QByteArray &xml, const QString &localTagName) const
{
    QXmlStreamReader reader(xml);
    while (!reader.atEnd()) {
        reader.readNext();
        if (reader.isStartElement() && reader.name().toString().compare(localTagName, Qt::CaseInsensitive) == 0) {
            return reader.readElementText().trimmed();
        }
    }
    return {};
}

QVector<QString> OnvifClient::parseTagValues(const QByteArray &xml, const QString &localTagName) const
{
    QVector<QString> values;
    QXmlStreamReader reader(xml);
    while (!reader.atEnd()) {
        reader.readNext();
        if (reader.isStartElement() && reader.name().toString().compare(localTagName, Qt::CaseInsensitive) == 0) {
            values.push_back(reader.readElementText().trimmed());
        }
    }
    return values;
}

QString OnvifClient::resolveDeviceServiceUrl(const QString &deviceUrl) const
{
    QUrl url(deviceUrl);
    if (!url.isValid()) {
        return {};
    }

    if (url.path().isEmpty() || url.path() == QStringLiteral("/")) {
        url.setPath(QStringLiteral("/onvif/device_service"));
    }
    return url.toString();
}

QString OnvifClient::getMediaServiceUrl(const QString &deviceUrl)
{
    const QString serviceUrl = resolveDeviceServiceUrl(deviceUrl);
    if (serviceUrl.isEmpty()) {
        return {};
    }

    const QString bodyInner =
        QStringLiteral("<tds:GetCapabilities xmlns:tds=\"http://www.onvif.org/ver10/device/wsdl\">"
                       "<tds:Category>Media</tds:Category>"
                       "</tds:GetCapabilities>");

    QString errorText;
    const QByteArray reply = sendSoapRequest(
        QUrl(serviceUrl),
        QStringLiteral("http://www.onvif.org/ver10/device/wsdl/GetCapabilities"),
        bodyInner,
        &errorText);

    if (reply.isEmpty()) {
        publishError(QStringLiteral("GetCapabilities(Media) failed for %1: %2").arg(deviceUrl, errorText));
        return {};
    }

    QString mediaXAddr = parseFirstTagText(reply, QStringLiteral("XAddr"));
    if (mediaXAddr.isEmpty()) {
        const QRegularExpression rx(QStringLiteral("<[^:>]*:?Media\\b[^>]*>.*?<[^:>]*:?XAddr>([^<]+)</[^:>]*:?XAddr>"),
                                    QRegularExpression::DotMatchesEverythingOption);
        const QRegularExpressionMatch match = rx.match(QString::fromUtf8(reply));
        if (match.hasMatch()) {
            mediaXAddr = match.captured(1).trimmed();
        }
    }
    if (mediaXAddr.isEmpty()) {
        LOG_INFO_MSG(
            (QStringLiteral("ONVIF GetCapabilities(Media): XAddr not found, preview: ") + previewXml(reply))
                .toStdString());
    }
    return mediaXAddr;
}

QString OnvifClient::getFirstProfileToken(const QString &mediaServiceUrl)
{
    const QString bodyInner =
        QStringLiteral("<trt:GetProfiles xmlns:trt=\"http://www.onvif.org/ver10/media/wsdl\"/>");

    QString errorText;
    const QByteArray reply = sendSoapRequest(
        QUrl(mediaServiceUrl),
        QStringLiteral("http://www.onvif.org/ver10/media/wsdl/GetProfiles"),
        bodyInner,
        &errorText);

    if (reply.isEmpty()) {
        publishError(QStringLiteral("GetProfiles failed for %1: %2").arg(mediaServiceUrl, errorText));
        return {};
    }

    QXmlStreamReader reader(reply);
    while (!reader.atEnd()) {
        reader.readNext();
        if (reader.isStartElement() && reader.name().toString().compare(QStringLiteral("Profiles"), Qt::CaseInsensitive) == 0) {
            const auto attrs = reader.attributes();
            const QString token = attrs.value(QStringLiteral("token")).toString();
            if (!token.isEmpty()) {
                return token;
            }
        }
    }
    LOG_INFO_MSG(
        (QStringLiteral("ONVIF GetProfiles: no Profiles element with token=, preview: ") + previewXml(reply))
            .toStdString());
    return {};
}

void OnvifClient::publishError(const QString &errorText)
{
    if (errorText.isEmpty()) {
        return;
    }
    LOG_CRITICAL_MSG(errorText.toStdString());
    emit errorOccurred(errorText);
}
