#include "devices.h"
#include "ui_devices.h"
#include "adddevice.h"

Devices::Devices(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Devices)
{
    ui->setupUi(this);
    ic = 0;
    Dev_Query = new QSqlQuery;
    Dev_Query->prepare("SELECT  devices.\"deviceId\", devicetypes.description \"type\", devices.\"addDate\", devices.\"connectionString\", "
                       "resolutions.width, resolutions.height, devices.transform, devices.caption FROM devices INNER JOIN devicetypes ON devices.type=devicetypes.\"deviceTypeId\""
                       " INNER JOIN resolutions ON devices.resolution=resolutions.\"resolutionId\";");
    if(!Dev_Query->exec())
    {
        qDebug() << "Unable to get devicelist" << Dev_Query->lastError() << Dev_Query->lastQuery();
    }
    //Dev_Query->first();
    while (Dev_Query->next()) {
        ic++;
        devpic_Label = new QLabel(this);
        devtitle_Label = new QLabel;
        devtype_Label = new QLabel;
        devtype_Label->show();
        devpic_Label->show();
        devtitle_Label->show();
        devndesc_Layout = new QBoxLayout(QBoxLayout::LeftToRight);
        ui->devList_Layout->addLayout(devndesc_Layout,ic, 1, Qt::Alignment(0x0001));
        devndesc_Layout->addWidget(devpic_Label);
        devndesc_Layout->addWidget(devtitle_Label);
        devndesc_Layout->addWidget(devtype_Label);
        devtitle_Label->setText("<h3>"+Dev_Query->value(7).toString()+"</h3>");
        devtype_Label->setText("<h3>("+Dev_Query->value(1).toString()+")</h3>");


    }

}

Devices::~Devices()
{



    delete ui;

}

void Devices::on_AddDevice_Button_clicked()
{
    //Отображение формы добавления камеры
    AddDevice dev;
    dev.setModal(true);
    dev.exec();
}

void Devices::on_DeleteDevice_Button_clicked()
{ //Удаление камеры
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Удаление устройства", "Вы уверены, что хотите удалить устройство?", QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        QSqlQuery DeleteDev_Query;
        DeleteDev_Query.prepare("DELETE FROM devices WHERE \"deviceId\" = :devid;");
        //DeleteDev_Query.bindValue(":devid", )
        if(!DeleteDev_Query.exec())
        {
            qDebug() << "Unable to delete device" << DeleteDev_Query.lastError() << DeleteDev_Query.lastQuery();
        }
        else
        {
            QMessageBox::information(this, "Удаление устройства", "Устройство успешно удалено");
        }
    }

}
