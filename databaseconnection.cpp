#include "databaseconnection.h"
#include "users.h"
#include "eventlog.h"
#include "mandatorygroups.h"
DataBaseConnection::DataBaseConnection(QObject *parent) : QObject(parent)
{

}

bool DataBaseConnection::CreateConnection(QString HostName, QString DBName, QString UserName, QString Password, int Port)
{
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

        db.driver()->subscribeToNotification("insert_users_notf");
        SendAlert_var = new SendAlert; //Создание динамического объекта посылателя событий
        SendAlert_var->prepare(); //Подготовка события
        SendAlert_var->setUser(UserName);
        SendAlert_var->setSignature(1);                 //Присвоение сигнатуры события
        SendAlert_var->send();                          //Отправка события
        delete SendAlert_var; //Удаление динамического объекта посылателя сообщений
        return true;
    }
}


