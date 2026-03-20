#include "COnvifSetupDialog.h"
#include "COnvifManualAdd.h"
#include "ui_COnvifSetupDialog.h"

#include <QComboBox>
#include <QFutureWatcher>
#include <QMessageBox>
#include <QPushButton>

#include "Loggerd.h"

COnvifSetupDialog::COnvifSetupDialog(QWidget *parent)
    : QDialog(parent)
    , m_pUi(new Ui::COnvifSetupDialog)
    , m_pOnvifClient(new OnvifClient(this))
{
    m_pUi->setupUi(this);

    m_pUi->Credentials_GroupBox->setToolTip(
        tr("HiWatch / Hikvision OEM: use the same login as the camera web interface. "
           "Enable ONVIF and HTTP/HTTPS under Network or Integration settings."));
    m_pUi->OnvifHost_Edit->setToolTip(
        tr("Enter the camera IP, or IP:port (e.g. 192.168.1.64:8000), or full URL "
           "http://IP:port/onvif/device_service — port is often 80, 8000, or 8080 on HiWatch."));
    m_pUi->OpenOnvifManualDialog_Button->setToolTip(
        tr("If discovery fails, open manual entry: Device Service URL + profile token from the camera "
           "(Hikvision/HiWatch RTSP path is often /Streaming/Channels/101)."));

    connect(m_pUi->OnvifSearchByIp_Button, &QPushButton::clicked, this, &COnvifSetupDialog::onSearchByIpClicked);
    connect(m_pUi->DiscoverOnvif_Button, &QPushButton::clicked, this, &COnvifSetupDialog::onDiscoverClicked);
    connect(m_pUi->OnvifDevices_ComboBox, qOverload<int>(&QComboBox::currentIndexChanged), this,
            &COnvifSetupDialog::onCameraSelected);
    connect(m_pUi->OpenOnvifManualDialog_Button, &QPushButton::clicked, this, &COnvifSetupDialog::onManualAddClicked);

    connect(m_pOnvifClient, &OnvifClient::errorOccurred, this, [this](const QString &errorText) {
        m_pUi->OnvifStatus_Label->setText(errorText);
    });

    connect(m_pUi->buttonBox, &QDialogButtonBox::accepted, this, &COnvifSetupDialog::onDialogAccepted);
    connect(m_pUi->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    LOG_INFO_MSG("COnvifSetupDialog constructed");
}

COnvifSetupDialog::~COnvifSetupDialog()
{
    delete m_pUi;
}

QString COnvifSetupDialog::selectedRtspUrl() const
{
    return m_storedRtspUrl;
}

QString COnvifSetupDialog::suggestedCaption() const
{
    return m_storedCaption;
}

void COnvifSetupDialog::onSearchByIpClicked()
{
    const QString host = m_pUi->OnvifHost_Edit->text().trimmed();
    if (host.isEmpty()) {
        QMessageBox::warning(this, tr("ONVIF"), tr("Enter IP address or hostname (or full device service URL)."));
        return;
    }

    m_pOnvifClient->setCredentials(
        m_pUi->OnvifUsername_Edit->text().trimmed(),
        m_pUi->OnvifPassword_Edit->text());

    if (m_pUi->OnvifUsername_Edit->text().trimmed().isEmpty() && m_pUi->OnvifPassword_Edit->text().isEmpty()) {
        LOG_INFO_MSG(
            "ONVIF search by IP: username/password empty — device may be found but GetCapabilities/GetStreamUri "
            "will return \"Host requires authentication\" without credentials.");
    }

    m_pUi->OnvifStatus_Label->setText(tr("Searching ONVIF at the given address..."));
    m_pUi->OnvifSearchByIp_Button->setEnabled(false);

    auto future = m_pOnvifClient->discoverCameraByHostAsync(host);
    auto *watcher = new QFutureWatcher<OnvifCamera>(this);

    connect(watcher, &QFutureWatcher<OnvifCamera>::finished, this, [this, watcher]() {
        const OnvifCamera camera = watcher->result();

        if (camera.name.isEmpty()) {
            m_pUi->OnvifStatus_Label->setText(
                tr("Device not found or not responding to ONVIF (check IP, ports, and credentials)."));
            m_cameras.clear();
            m_pUi->OnvifDevices_ComboBox->clear();
            m_storedRtspUrl.clear();
            m_storedCaption.clear();
        } else {
            m_cameras.clear();
            m_cameras.push_back(camera);
            m_pUi->OnvifDevices_ComboBox->clear();
            const QString title = QStringLiteral("%1 (%2)")
                                      .arg(camera.model.isEmpty() ? camera.name : camera.model,
                                           camera.manufacturer.isEmpty() ? QStringLiteral("ONVIF")
                                                                           : camera.manufacturer);
            m_pUi->OnvifDevices_ComboBox->addItem(title);
            m_pUi->OnvifStatus_Label->setText(tr("Device found by IP."));
            onCameraSelected(0);
        }

        m_pUi->OnvifSearchByIp_Button->setEnabled(true);
        watcher->deleteLater();
    });

    watcher->setFuture(future);
}

void COnvifSetupDialog::onDiscoverClicked()
{
    m_pOnvifClient->setCredentials(
        m_pUi->OnvifUsername_Edit->text().trimmed(),
        m_pUi->OnvifPassword_Edit->text());

    if (m_pUi->OnvifUsername_Edit->text().trimmed().isEmpty() && m_pUi->OnvifPassword_Edit->text().isEmpty()) {
        LOG_INFO_MSG(
            "ONVIF WS-Discovery: username/password empty — after selecting a camera, device/media calls may "
            "require authentication.");
    }

    m_pUi->OnvifStatus_Label->setText(tr("Searching for cameras on the local network..."));
    m_pUi->DiscoverOnvif_Button->setEnabled(false);

    auto future = m_pOnvifClient->discoverCamerasAsync();
    auto *watcher = new QFutureWatcher<QVector<OnvifCamera>>(this);

    connect(watcher, &QFutureWatcher<QVector<OnvifCamera>>::finished, this, [this, watcher]() {
        m_cameras = watcher->result();
        m_pUi->OnvifDevices_ComboBox->clear();

        for (const OnvifCamera &camera : std::as_const(m_cameras)) {
            const QString title = QStringLiteral("%1 (%2)")
                                      .arg(camera.model.isEmpty() ? camera.name : camera.model,
                                           camera.manufacturer);
            m_pUi->OnvifDevices_ComboBox->addItem(title);
        }

        if (m_cameras.isEmpty()) {
            m_pUi->OnvifStatus_Label->setText(tr("No ONVIF cameras found."));
            m_storedRtspUrl.clear();
            m_storedCaption.clear();
        } else {
            m_pUi->OnvifStatus_Label->setText(tr("Found cameras: %1").arg(m_cameras.size()));
            onCameraSelected(0);
        }

        m_pUi->DiscoverOnvif_Button->setEnabled(true);
        watcher->deleteLater();
    });

    watcher->setFuture(future);
}

void COnvifSetupDialog::onCameraSelected(int index)
{
    if (index < 0 || index >= m_cameras.size()) {
        return;
    }

    const OnvifCamera &camera = m_cameras.at(index);
    m_storedRtspUrl = camera.rtspUrl;
    m_storedCaption = camera.model.isEmpty() ? camera.name : camera.model;

    if (!m_storedRtspUrl.isEmpty()) {
        m_pUi->OnvifStatus_Label->setText(tr("Camera selected, RTSP URL is ready."));
    } else {
        m_pUi->OnvifStatus_Label->setText(tr("Camera selected but RTSP URL is empty — try manual entry."));
    }
}

void COnvifSetupDialog::onManualAddClicked()
{
    COnvifManualAdd dlg(this);
    dlg.setInitialCredentials(
        m_pUi->OnvifUsername_Edit->text(),
        m_pUi->OnvifPassword_Edit->text());
    dlg.setWindowModality(Qt::WindowModal);

    if (dlg.exec() != QDialog::Accepted) {
        return;
    }

    const QString rtsp = dlg.rtspUrl().trimmed();
    if (rtsp.isEmpty()) {
        return;
    }

    m_storedRtspUrl = rtsp;
    m_storedCaption.clear();
    m_pUi->OnvifStatus_Label->setText(tr("RTSP URL obtained from manual entry."));
}

void COnvifSetupDialog::onDialogAccepted()
{
    if (m_storedRtspUrl.trimmed().isEmpty()) {
        QMessageBox::warning(
            this,
            tr("ONVIF"),
            tr("No RTSP URL. Run a search, pick a camera from the list, or use manual entry."));
        return;
    }
    accept();
}
