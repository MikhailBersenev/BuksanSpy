#include "CDevices.h"
#include "ui_CDevices.h"
#include "CAddDevice.h"
#include <QMessageBox>
#include "Loggerd.h"

CDevices::CDevices(QWidget *parent) :
    QDialog(parent),
    m_pUi(new Ui::CDevices)
{
    m_pUi->setupUi(this);
    m_nIc = 0;
    m_pDevQuery = new QSqlQuery;
    m_pDevQuery->prepare("SELECT  devices.\"deviceId\", devicetypes.description \"type\", devices.\"addDate\", devices.\"connectionString\", "
                       "resolutions.width, resolutions.height, devices.transform, devices.caption FROM devices INNER JOIN devicetypes ON devices.type=devicetypes.\"deviceTypeId\""
                       " INNER JOIN resolutions ON devices.resolution=resolutions.\"resolutionId\";");
    LOG_INFO_MSG("CDevices dialog constructed");
    if(!m_pDevQuery->exec())
    {
        LOG_CRITICAL_MSG((QStringLiteral("Unable to get devicelist ") + m_pDevQuery->lastError().text() + QLatin1Char(' ') + m_pDevQuery->lastQuery()).toStdString());
    }
    
    while (m_pDevQuery->next()) {
        m_nIc++;
        m_pDevPicLabel = new QLabel(this);
        m_pDevTitleLabel = new QLabel;
        m_pDevTypeLabel = new QLabel;
        m_pDevTypeLabel->show();
        m_pDevPicLabel->show();
        m_pDevTitleLabel->show();
        m_pDevDescLayout = new QBoxLayout(QBoxLayout::LeftToRight);
        m_pUi->devList_Layout->addLayout(m_pDevDescLayout, m_nIc, 1, Qt::Alignment(0x0001));
        m_pDevDescLayout->addWidget(m_pDevPicLabel);
        m_pDevDescLayout->addWidget(m_pDevTitleLabel);
        m_pDevDescLayout->addWidget(m_pDevTypeLabel);
        m_pDevTitleLabel->setText("<h3>" + m_pDevQuery->value(7).toString() + "</h3>");
        m_pDevTypeLabel->setText("<h3>(" + m_pDevQuery->value(1).toString() + ")</h3>");
    }
}

CDevices::~CDevices()
{
    delete m_pUi;
}

void CDevices::on_AddDevice_Button_clicked()
{
    //Отображение формы добавления камеры
    CAddDevice l_dev;
    l_dev.setModal(true);
    l_dev.exec();
}

void CDevices::on_DeleteDevice_Button_clicked()
{ //Удаление камеры
    QMessageBox::StandardButton l_reply;
    l_reply = QMessageBox::question(this, "Device removal", "Are you sure you want to remove this device?", QMessageBox::Yes|QMessageBox::No);
    if(l_reply == QMessageBox::Yes)
    {
        QSqlQuery l_deleteDevQuery;
        l_deleteDevQuery.prepare("DELETE FROM devices WHERE \"deviceId\" = :devid;");
        //l_deleteDevQuery.bindValue(":devid", )
        if(!l_deleteDevQuery.exec())
        {
            LOG_CRITICAL_MSG((QStringLiteral("Unable to delete device ") + l_deleteDevQuery.lastError().text() + QLatin1Char(' ') + l_deleteDevQuery.lastQuery()).toStdString());
        }
        else
        {
            QMessageBox::information(this, "Device removal", "Device was removed successfully");
        }
    }
}
