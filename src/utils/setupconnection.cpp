#include "setupconnection.h"
#include "ui_setupconnection.h"
#include <QtSql>
#include <QDebug>
#include <QtWidgets>

SetupConnection::SetupConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetupConnection)
{
    ui->setupUi(this);



}

SetupConnection::~SetupConnection()
{
    delete ui;
}

void SetupConnection::on_TryConnect_Button_clicked()
{
    //Обработчик для кнопки с проверкой на пустые поля

    if (!(ui->HostName_Edit->text()=="" or ui->DBName_Edit->text()=="" or ui->UserName_Edit->text()=="" or ui->Password_Edit->text()==""))
    {
        if(!PostgresConnection->CreateConnection(ui->HostName_Edit->text(), ui->DBName_Edit->text(), ui->UserName_Edit->text(), ui->Password_Edit->text(), ui->Port_Edit->text().toInt()))
        {
            QMessageBox::critical(this, "Ошибка", "Не удалось соединиться, возможно вы ввели неверные данные \n или не находитесь в одной сети с сервером \n "
                                                  "Ошибка SQL: "+PostgresConnection->db.lastError().databaseText());
        }
        else
        {
            QMessageBox::information(this, "Подключение выполнено", "Подключение выполнено. Нажмите ОК для продолжения");
            close();
        }
    }
    else {
        QMessageBox::warning(this, "Внимание!", "Поля не могут быть пустыми");
    }

}




