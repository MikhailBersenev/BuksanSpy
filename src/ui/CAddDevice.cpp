#include "CAddDevice.h"
#include "COnvifSetupDialog.h"
#include "camera/CCameraVideoCapture.h"
#include "camera/CAddDevicePreviewViewFinder.h"
#include "ui_CAddDevice.h"
#include <QtWidgets>
#include <QComboBox>
#include <QLineEdit>
#include <QMediaDevices>
#include <QCameraDevice>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDate>
#include "Loggerd.h"

CAddDevice::CAddDevice(QWidget *parent) :
    QDialog(parent),
    m_pUi(new Ui::CAddDevice)
{
    m_pUi->setupUi(this);
    m_pRtspEdit = new QLineEdit(this);
    m_pWebcameraComboBox = new QComboBox(this);
    m_pResolutionsModel = new QSqlQueryModel(this);

    m_pUi->SelectDevice_Layout->addWidget(m_pWebcameraComboBox);
    m_pUi->SelectDevice_Layout->addWidget(m_pRtspEdit);
    m_pRtspEdit->setPlaceholderText("rtsp://user:password@ip:554/stream");

    fSetMode(1);

    m_pResolutionsModel->setQuery("SELECT * FROM resolutions;");
    m_pUi->Resolution_ComboBox->setModel(&*m_pResolutionsModel);
    m_pUi->Resolution_ComboBox->setModelColumn(3);

    connect(m_pUi->OnvifSetup_Button, &QPushButton::clicked, this, &CAddDevice::onOnvifSetupClicked);
    connect(m_pUi->Preview_Button, &QPushButton::clicked, this, &CAddDevice::onPreviewButtonClicked);

    m_pPreviewViewFinder = new CAddDevicePreviewViewFinder(m_pUi->Preview_Container);
    m_pPreviewViewFinder->setMinimumSize(320, 180);
    m_pPreviewViewFinder->setScalingMode(AbstractViewFinder::ScalingMode::Fit);
    m_pUi->Preview_VLayout->insertWidget(0, m_pPreviewViewFinder);

    LOG_INFO_MSG("CAddDevice dialog constructed");
}

CAddDevice::~CAddDevice()
{
    stopPreview();
    delete m_pUi;
}

void CAddDevice::fSetMode(int nMode)
{
    switch (nMode) {
    case 0:
        m_pWebcameraComboBox->hide();
        m_pRtspEdit->show();
        m_pUi->SelectDevice_Label->setText("RTSP stream:");
        m_pUi->OnvifSetup_Button->show();
        m_pUi->Preview_Container->show();
        break;
    case 1: {
        stopPreview();
        m_pRtspEdit->hide();
        m_pWebcameraComboBox->show();
        m_pUi->SelectDevice_Label->setText("Device:");
        m_pUi->OnvifSetup_Button->hide();
        m_pUi->Preview_Container->hide();
        m_pWebcameraComboBox->clear();
        const QList<QCameraDevice> devices = QMediaDevices::videoInputs();
        for (const QCameraDevice &device : devices) {
            m_pWebcameraComboBox->addItem(device.description(), QString::fromUtf8(device.id()));
        }
        break;
    }
    }
}

void CAddDevice::stopPreview()
{
    if (!m_pPreviewCapture) {
        return;
    }
    m_pPreviewCapture->requestInterruption();
    m_pPreviewCapture->wait(15000);
    disconnect(m_pPreviewCapture, nullptr, this, nullptr);
    delete m_pPreviewCapture;
    m_pPreviewCapture = nullptr;
}

void CAddDevice::onPreviewButtonClicked()
{
    if (m_pPreviewCapture) {
        stopPreview();
        m_pUi->Preview_Button->setText(QStringLiteral("Start preview"));
        if (m_pPreviewViewFinder) {
            m_pPreviewViewFinder->clearFrame();
        }
        return;
    }

    const QString url = m_pRtspEdit->text().trimmed();
    if (url.isEmpty()) {
        QMessageBox::warning(this, QStringLiteral("Preview"), QStringLiteral("Enter RTSP URL first."));
        return;
    }

    auto *cap = new CCameraVideoCapture(this);
    cap->isRecording = false;
    cap->mVideoCap = cv::VideoCapture(url.toStdString(), cv::CAP_FFMPEG);
    if (!cap->mVideoCap.isOpened()) {
        QMessageBox::warning(this, QStringLiteral("Preview"),
                             QStringLiteral("Could not open stream. Check URL and network."));
        delete cap;
        return;
    }

    m_pPreviewCapture = cap;
    connect(m_pPreviewCapture, &CCameraVideoCapture::newPixmapCaptured, this,
            &CAddDevice::onPreviewFrameReady, Qt::QueuedConnection);
    m_pPreviewCapture->start();
    m_pUi->Preview_Button->setText(QStringLiteral("Stop preview"));
    if (m_pPreviewViewFinder) {
        m_pPreviewViewFinder->clearFrame();
    }
}

void CAddDevice::onPreviewFrameReady()
{
    if (!m_pPreviewCapture || !m_pPreviewViewFinder) {
        return;
    }
    const QPixmap pm = m_pPreviewCapture->pixmap();
    if (pm.isNull()) {
        return;
    }
    m_pPreviewViewFinder->displayFrame(pm.toImage());
}

void CAddDevice::on_buttonBox_accepted()
{
    QSqlQuery l_addDeviceQuery;
    QSqlQuery l_checkExistQuery;
    l_checkExistQuery.prepare("SELECT \"connectionString\" FROM devices WHERE \"connectionString\" = :connectionstr;");
    l_addDeviceQuery.prepare("INSERT INTO devices (type, \"addDate\", \"connectionString\", resolution, transform, caption) VALUES (:devtype, :date, :connectionstr, :resolution, :transform, :caption);");
    QString connectionString;

    switch (m_pUi->DevType_ComboBox->model()->index(m_pUi->DevType_ComboBox->currentIndex(),0).data().toInt()) {
    case 0:
        connectionString = m_pWebcameraComboBox->currentData().toString();
        if (connectionString.isEmpty()) {
            connectionString = QString::number(m_pWebcameraComboBox->currentIndex());
        }
        l_addDeviceQuery.bindValue(":devtype", 1);
        break;
    case 1:
        connectionString = m_pRtspEdit->text().trimmed();
        l_addDeviceQuery.bindValue(":devtype", 2);
        break;
    }

    if (connectionString.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Provide connection string please");
        return;
    }

    l_addDeviceQuery.bindValue(":connectionstr", connectionString);
    l_checkExistQuery.bindValue(":connectionstr", connectionString);
    l_addDeviceQuery.bindValue(":caption", m_pUi->Caption_Edit->text());
    l_addDeviceQuery.bindValue(":date", QDate::currentDate());
    l_addDeviceQuery.bindValue(":resolution", m_pUi->Resolution_ComboBox->model()->index(m_pUi->Resolution_ComboBox->currentIndex(),0).data().toInt());
    l_addDeviceQuery.bindValue(":transform", m_pUi->Transform_ComboBox->currentText().right(3));
    if(!l_checkExistQuery.exec())
    {
        LOG_CRITICAL_MSG((QStringLiteral("Unable to check device existence ") + l_checkExistQuery.lastError().text() + QLatin1Char(' ') + l_checkExistQuery.lastQuery()).toStdString());
    }
    l_checkExistQuery.first();
    if(!l_checkExistQuery.isNull(0))
    {
        QMessageBox::warning(this, "Add device", "This device is already added");
    }
    else
    {
        if(!m_pUi->Caption_Edit->text().isEmpty())
        {
            if(!l_addDeviceQuery.exec())
            {
                LOG_CRITICAL_MSG((QStringLiteral("Unable to add device information ") + l_addDeviceQuery.lastError().text() + QLatin1Char(' ') + l_addDeviceQuery.lastQuery()).toStdString());
                return;
            }
            else
            {
                QMessageBox::information(this, "Information", "Device was added successfully");
            }
        }
        else
        {
            QMessageBox::warning(this, "Warning", "Provide device name please");
        }
    }
}



void CAddDevice::on_DevType_ComboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        fSetMode(1);
        break;
    case 1:
        fSetMode(0);
        break;

    }
}

void CAddDevice::onOnvifSetupClicked()
{
    COnvifSetupDialog dlg(this);
    dlg.setWindowModality(Qt::WindowModal);
    if (dlg.exec() != QDialog::Accepted) {
        return;
    }

    const QString rtsp = dlg.selectedRtspUrl().trimmed();
    if (!rtsp.isEmpty()) {
        m_pRtspEdit->setText(rtsp);
    }

    const QString cap = dlg.suggestedCaption().trimmed();
    if (!cap.isEmpty() && m_pUi->Caption_Edit->text().trimmed().isEmpty()) {
        m_pUi->Caption_Edit->setText(cap);
    }
}
