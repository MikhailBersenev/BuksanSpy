#include "COnvifManualAdd.h"
#include "ui_COnvifManualAdd.h"

#include <QFutureWatcher>
#include <QMessageBox>
#include <QPushButton>

#include "Loggerd.h"

COnvifManualAdd::COnvifManualAdd(QWidget *parent)
    : QDialog(parent)
    , m_pUi(new Ui::COnvifManualAdd)
    , m_pOnvifClient(new OnvifClient(this))
{
    m_pUi->setupUi(this);
    m_pUi->RtspResult_Edit->setReadOnly(true);
    m_pUi->RtspResult_Edit->setPlaceholderText(tr("RTSP URL appears here after a successful request"));

    m_pUi->DeviceUrl_Edit->setToolTip(
        tr("HiWatch / Hikvision: typically http://IP:8000/onvif/device_service (or port 80) — "
           "enable ONVIF under Network / Integration in the camera web UI."));
    m_pUi->ProfileToken_Edit->setToolTip(
        tr("Often MediaProfile000, Profile_1, or similar — from ONVIF Device Manager or the camera API docs."));

    connect(m_pOnvifClient, &OnvifClient::errorOccurred, this, [this](const QString &errorText) {
        m_pUi->Status_Label->setText(errorText);
    });

    connect(m_pUi->GetRtsp_Button, &QPushButton::clicked, this, &COnvifManualAdd::onGetRtspClicked);
    connect(m_pUi->buttonBox, &QDialogButtonBox::accepted, this, &COnvifManualAdd::onAccepted);
    connect(m_pUi->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    LOG_INFO_MSG("COnvifManualAdd dialog constructed");
}

COnvifManualAdd::~COnvifManualAdd()
{
    delete m_pUi;
}

QString COnvifManualAdd::rtspUrl() const
{
    return m_rtspUrl;
}

void COnvifManualAdd::setInitialCredentials(const QString &username, const QString &password)
{
    m_pUi->Username_Edit->setText(username);
    m_pUi->Password_Edit->setText(password);
}

void COnvifManualAdd::onGetRtspClicked()
{
    const QString deviceUrl = m_pUi->DeviceUrl_Edit->text().trimmed();
    const QString profileToken = m_pUi->ProfileToken_Edit->text().trimmed();

    if (deviceUrl.isEmpty() || profileToken.isEmpty()) {
        QMessageBox::warning(this, tr("ONVIF"), tr("Enter Device Service URL and Profile Token."));
        return;
    }

    m_pOnvifClient->setCredentials(
        m_pUi->Username_Edit->text().trimmed(),
        m_pUi->Password_Edit->text());

    m_rtspUrl.clear();
    m_pUi->RtspResult_Edit->clear();
    m_pUi->GetRtsp_Button->setEnabled(false);
    m_pUi->Status_Label->setText(tr("Requesting RTSP URL from device..."));

    auto future = m_pOnvifClient->getRtspUrlAsync(deviceUrl, profileToken);
    auto *watcher = new QFutureWatcher<QString>(this);

    connect(watcher, &QFutureWatcher<QString>::finished, this, [this, watcher]() {
        const QString rtsp = watcher->result().trimmed();
        if (rtsp.isEmpty()) {
            m_pUi->Status_Label->setText(tr("Could not get RTSP URL. Check URL, token, and credentials."));
        } else {
            m_rtspUrl = rtsp;
            m_pUi->RtspResult_Edit->setText(rtsp);
            m_pUi->Status_Label->setText(tr("RTSP URL received."));
        }
        m_pUi->GetRtsp_Button->setEnabled(true);
        watcher->deleteLater();
    });

    watcher->setFuture(future);
}

void COnvifManualAdd::onAccepted()
{
    if (m_rtspUrl.trimmed().isEmpty()) {
        QMessageBox::information(
            this,
            tr("ONVIF"),
            tr("Click Get RTSP URL first and wait for success, or press Cancel."));
        return;
    }
    accept();
}
