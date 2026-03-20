#ifndef ONVIFCLIENT_H
#define ONVIFCLIENT_H

#include <QFuture>
#include <QMutex>
#include <QNetworkRequest>
#include <QObject>
#include <QString>
#include <QUrl>
#include <QVector>

/**
 * @brief ONVIF camera descriptor used by OnvifClient.
 *
 * Contains basic device metadata and stream-related fields collected from
 * ONVIF Device and Media services.
 */
struct OnvifCamera
{
    QString name;
    QString model;
    QString manufacturer;
    QString firmwareVersion;
    QString hardwareId;
    QString rtspUrl;
    bool ptzSupported = false;
};

/**
 * @brief Drop-in ONVIF discovery and capability client for BuksanSpy.
 *
 * The client discovers ONVIF devices using WS-Discovery (UDP multicast) and
 * requests SOAP endpoints through Qt Network. Methods are available in blocking
 * form for straightforward integration and in asynchronous form through QFuture
 * and signals for worker-thread usage.
 *
 * Typical usage:
 * 1) Call discoverCameras() or discoverCamerasAsync()
 * 2) For each device URL, call getCameraCapabilities()
 * 3) Build stream URL using getRtspUrl(deviceUrl, profileToken)
 */
class OnvifClient : public QObject
{
    Q_OBJECT

public:
    explicit OnvifClient(QObject *parent = nullptr);
    ~OnvifClient() override = default;

    QVector<OnvifCamera> discoverCameras();
    OnvifCamera getCameraCapabilities(const QString &deviceUrl);
    QString getRtspUrl(const QString &deviceUrl, const QString &profileToken);

    QFuture<QVector<OnvifCamera>> discoverCamerasAsync();
    QFuture<OnvifCamera> getCameraCapabilitiesAsync(const QString &deviceUrl);
    QFuture<QString> getRtspUrlAsync(const QString &deviceUrl, const QString &profileToken);

    void setRequestTimeoutMs(int timeoutMs);
    void setDiscoveryTimeoutMs(int timeoutMs);

    /**
     * @brief ONVIF device credentials (WS-Security UsernameToken digest + optional HTTP auth).
     *
     * Used for SOAP calls to Device/Media services. WS-Discovery does not use credentials.
     * Set before getCameraCapabilities / getRtspUrl / discoverCameras (per-device queries).
     */
    void setCredentials(const QString &username, const QString &password);
    QString username() const;
    QString password() const;

    /**
     * @brief Resolve ONVIF Device Service by IP or hostname (tries common HTTP/HTTPS ports).
     *
     * Pass an IP (`192.168.1.10`), hostname, or full service URL (tried first).
     * @return Device service URL (e.g. `http://192.168.1.10/onvif/device_service`) or empty.
     */
    QString findDeviceServiceUrlByHost(const QString &hostOrUrl);

    /**
     * @brief Resolve device by IP/host and query capabilities (same as after WS-Discovery).
     */
    OnvifCamera discoverCameraByHost(const QString &hostOrUrl);

    QFuture<OnvifCamera> discoverCameraByHostAsync(const QString &hostOrUrl);

signals:
    void camerasDiscovered(const QVector<OnvifCamera> &cameras);
    void capabilitiesReceived(const QString &deviceUrl, const OnvifCamera &camera);
    void rtspUrlReceived(const QString &deviceUrl, const QString &profileToken, const QString &rtspUrl);
    void errorOccurred(const QString &errorText);

private:
    QString makeDiscoveryProbeMessage() const;
    QVector<QString> discoverDeviceUrls();

    QByteArray sendSoapRequest(
        const QUrl &url,
        const QString &soapAction,
        const QString &bodyInnerXml,
        QString *errorText = nullptr);

    QString parseFirstTagText(const QByteArray &xml, const QString &localTagName) const;
    QVector<QString> parseTagValues(const QByteArray &xml, const QString &localTagName) const;

    QString resolveDeviceServiceUrl(const QString &deviceUrl) const;
    QString getMediaServiceUrl(const QString &deviceUrl);
    QString getFirstProfileToken(const QString &mediaServiceUrl);

    void publishError(const QString &errorText);

    QString buildSoapEnvelope(const QString &bodyInnerXml) const;

    /** HTTP Basic for the HTTP layer (many devices require it for Media Service along with WS-Security in SOAP). */
    void applyHttpAuthentication(QNetworkRequest &request) const;

    QVector<QUrl> buildCandidateOnvifDeviceUrls(const QString &host, int explicitPort = -1) const;
    struct HostProbeInput
    {
        QString host;
        int explicitPort = -1; /**< Port from URL or host:port form; -1 = probe common ports. */
    };
    static HostProbeInput parseHostForOnvif(const QString &hostOrUrl);

private:
    mutable QMutex m_mutex;
    int m_requestTimeoutMs;
    int m_discoveryTimeoutMs;
    QString m_username;
    QString m_password;
};

#endif // ONVIFCLIENT_H
