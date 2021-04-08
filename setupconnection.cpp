#include "setupconnection.h"
#include "ui_setupconnection.h"
#include <QtSql>
#include <QDebug>
#include <QtWidgets>
//Функция создания соединения с БД
bool SetupConnection::CreateConnection(QString HostName, QString DBName, QString UserName, QString Password, int Port) {
    db = QSqlDatabase::addDatabase("QPSQL"); //Задание драйвера
    db.setDatabaseName(DBName); //Имя пользователя
    db.setHostName(HostName);   //Хост
    db.setPort(Port);
    db.setUserName(UserName);   //Пользователь
    db.setPassword(Password);   //Пароль
    //Проверка на возможность соединения и соединение
    if(!db.open()) {
        qDebug() << "Unable to create connection"  << db.lastError();
        return false;
    }
    else
    {
        SendAlert_var = new SendAlert; //Создание динамического объекта посылателя событий
        SendAlert_var->prepare(); //Подготовка события
        SendAlert_var->setUser("SYSTEM");
        SendAlert_var->setSignature(1);                 //Присвоение сигнатуры события
        SendAlert_var->send();                          //Отправка события
        delete SendAlert_var; //Удаление динамического объекта посылателя сообщений
        return true;
    }
}
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
        if(!CreateConnection(ui->HostName_Edit->text(), ui->DBName_Edit->text(), ui->UserName_Edit->text(), ui->Password_Edit->text(), ui->Port_Edit->text().toInt()))
        {
            QMessageBox::critical(this, "Ошибка", "Не удалось соединиться, возможно вы ввели неверные данные \n или не находитесь в одной сети с сервером \n "
                                                  "Ошибка SQL: "+db.lastError().databaseText());
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


