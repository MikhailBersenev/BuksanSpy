#include "adddevice.h"
#include "ui_adddevice.h"
#include <QtWidgets>
#include <QMediaDevices>
#include <QCameraDevice>
AddDevice::AddDevice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDevice)
{
    ui->setupUi(this);
    rtsp_edit = new QLineEdit(this);
    SetMode(1);
    resolutions_model = new QSqlQueryModel(this);
    resolutions_model->setQuery("SELECT * FROM resolutions;");
    ui->Resolution_ComboBox->setModel(&*resolutions_model);
    ui->Resolution_ComboBox->setModelColumn(3);






}

AddDevice::~AddDevice()
{
    delete ui;
}

void AddDevice::SetMode(int mode)
{
    switch (mode) {
    case 0:
        delete webcamera_ComboBox;
        rtsp_edit = new QLineEdit;
        ui->SelectDevice_Layout->addWidget(rtsp_edit);
        ui->SelectDevice_Label->setText("RTSP поток:");
        break;
    case 1:
        QString devname;
        delete rtsp_edit;
        webcamera_ComboBox = new QComboBox;
        ui->SelectDevice_Layout->addWidget(webcamera_ComboBox);
        ui->SelectDevice_Label->setText("Устройство:");
        const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();
        for (const QCameraDevice &cameraDevice : cameras)
            webcamera_ComboBox->addItem(cameraDevice.description());
        break;
    }
}

void AddDevice::on_buttonBox_accepted()
{
    QSqlQuery AddDevice_Query;
    QSqlQuery CheckExist_Query;
    CheckExist_Query.prepare("SELECT \"connectionString\" FROM devices WHERE \"connectionString\" = :connectionstr;");
    AddDevice_Query.prepare("INSERT INTO devices (type, \"addDate\", \"connectionString\", resolution, transform, caption) VALUES (:devtype, :date, :connectionstr, :resolution, :transform, :caption);");
    CheckExist_Query.bindValue(":connectionstr", webcamera_ComboBox->currentText().right(1));
    switch (ui->DevType_ComboBox->model()->index(ui->DevType_ComboBox->currentIndex(),0).data().toInt()) {
    case 0:
        AddDevice_Query.bindValue(":connectionstr", webcamera_ComboBox->currentText().right(1));
        AddDevice_Query.bindValue(":devtype", 1);
        CheckExist_Query.bindValue(":connectionstr", webcamera_ComboBox->currentText().right(1));
        break;
    case 1:
        AddDevice_Query.bindValue(":connectionstr", rtsp_edit->text());
        AddDevice_Query.bindValue(":devtype", 2);
        CheckExist_Query.bindValue(":connectionstr", rtsp_edit->text().right(1));
        break;
    }
    AddDevice_Query.bindValue(":caption", ui->Caption_Edit->text());
    AddDevice_Query.bindValue(":date", QDate::currentDate());
    AddDevice_Query.bindValue(":resolution", ui->Resolution_ComboBox->model()->index(ui->Resolution_ComboBox->currentIndex(),0).data().toInt());
    AddDevice_Query.bindValue(":transform", ui->Transform_ComboBox->currentText().right(3));
    if(!CheckExist_Query.exec())
    {
        qDebug() << "Unable to check!!!" << CheckExist_Query.lastError() << CheckExist_Query.lastQuery();
    }
    CheckExist_Query.first();
    if(!CheckExist_Query.isNull(0))
    {
        QMessageBox::warning(this, "Добавление камеры", "Это устройство уже добавлено");
    }
    else
    {
        if(!ui->Caption_Edit->text().isEmpty())
        {
        if(!AddDevice_Query.exec())
        {
            qDebug() << "Unable to add device information" << AddDevice_Query.lastError() << AddDevice_Query.lastQuery();
            return;
        }
        else
        {
            QMessageBox::information(this, "Информация", "Устройство успешно добавлено");
        }
        }
        else
        {
            QMessageBox::warning(this, "Внимание", "Введите имя устройства");
        }
    }
}



void AddDevice::on_DevType_ComboBox_currentIndexChanged(int index)
{

    switch (index) {
    case 0:
        SetMode(1);
        break;
    case 1:
        SetMode(0);
        break;

    }
}


