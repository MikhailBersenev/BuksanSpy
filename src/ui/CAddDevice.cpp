#include "CAddDevice.h"
#include "ui_CAddDevice.h"
#include <QtWidgets>
#include <QComboBox>
#include <QLineEdit>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDate>

CAddDevice::CAddDevice(QWidget *parent) :
    QDialog(parent),
    m_pUi(new Ui::CAddDevice)
{
    m_pUi->setupUi(this);
    m_pRtspEdit = new QLineEdit(this);
    fSetMode(1);
    m_pResolutionsModel = new QSqlQueryModel(this);
    m_pResolutionsModel->setQuery("SELECT * FROM resolutions;");
    m_pUi->Resolution_ComboBox->setModel(&*m_pResolutionsModel);
    m_pUi->Resolution_ComboBox->setModelColumn(3);
}

CAddDevice::~CAddDevice()
{
    delete m_pUi;
}

void CAddDevice::fSetMode(int nMode)
{
    switch (nMode) {
    case 0:
        delete m_pWebcameraComboBox;
        m_pRtspEdit = new QLineEdit;
        m_pUi->SelectDevice_Layout->addWidget(m_pRtspEdit);
        m_pUi->SelectDevice_Label->setText("RTSP stream:");
        break;
    case 1:
        QString l_strDevName;
        delete m_pRtspEdit;
        m_pWebcameraComboBox = new QComboBox;
        m_pUi->SelectDevice_Layout->addWidget(m_pWebcameraComboBox);
        m_pUi->SelectDevice_Label->setText("Device:");
        // Временно убираем использование QMediaCDevices для совместимости
        m_pWebcameraComboBox->addItem("Камера 1");
        m_pWebcameraComboBox->addItem("Камера 2");
        break;
    }
}

void CAddDevice::on_buttonBox_accepted()
{
    QSqlQuery l_addDeviceQuery;
    QSqlQuery l_checkExistQuery;
    l_checkExistQuery.prepare("SELECT \"connectionString\" FROM devices WHERE \"connectionString\" = :connectionstr;");
    l_addDeviceQuery.prepare("INSERT INTO devices (type, \"addDate\", \"connectionString\", resolution, transform, caption) VALUES (:devtype, :date, :connectionstr, :resolution, :transform, :caption);");
    l_checkExistQuery.bindValue(":connectionstr", m_pWebcameraComboBox->currentText().right(1));
    switch (m_pUi->DevType_ComboBox->model()->index(m_pUi->DevType_ComboBox->currentIndex(),0).data().toInt()) {
    case 0:
        l_addDeviceQuery.bindValue(":connectionstr", m_pWebcameraComboBox->currentText().right(1));
        l_addDeviceQuery.bindValue(":devtype", 1);
        l_checkExistQuery.bindValue(":connectionstr", m_pWebcameraComboBox->currentText().right(1));
        break;
    case 1:
        l_addDeviceQuery.bindValue(":connectionstr", m_pRtspEdit->text());
        l_addDeviceQuery.bindValue(":devtype", 2);
        l_checkExistQuery.bindValue(":connectionstr", m_pRtspEdit->text().right(1));
        break;
    }
    l_addDeviceQuery.bindValue(":caption", m_pUi->Caption_Edit->text());
    l_addDeviceQuery.bindValue(":date", QDate::currentDate());
    l_addDeviceQuery.bindValue(":resolution", m_pUi->Resolution_ComboBox->model()->index(m_pUi->Resolution_ComboBox->currentIndex(),0).data().toInt());
    l_addDeviceQuery.bindValue(":transform", m_pUi->Transform_ComboBox->currentText().right(3));
    if(!l_checkExistQuery.exec())
    {
        qDebug() << "Unable to check!!!" << l_checkExistQuery.lastError() << l_checkExistQuery.lastQuery();
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
                qDebug() << "Unable to add device information" << l_addDeviceQuery.lastError() << l_addDeviceQuery.lastQuery();
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


