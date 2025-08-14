#include "sendalert.h"
#include "networkinfo.h"
#include <QDebug>
SendAlert::SendAlert(QObject *parent) : QObject(parent)
{

}
void SendAlert::prepare()
{ /*Подготовка SQL запроса и получение констант */
    MainQuery = new QSqlQuery;
    NetworkInfo ip;
    MainQuery->prepare("INSERT INTO alerts (\"user\", time, date, unixtime, signature, host, \"fullLog\")"
                       " VALUES (:user, :time, :date, :unixtime, :signature, :host, :fulllog);");
    MainQuery->bindValue(":time", QTime::currentTime());
    MainQuery->bindValue(":date", QDate::currentDate());
    MainQuery->bindValue(":host", ip.GetIPAddress());
    MainQuery->bindValue(":unixtime", QDateTime::currentSecsSinceEpoch());

}
void SendAlert::setUser(QString user)
{ //Бинд пользователя
    FindItem_Query = new QSqlQuery;
    FindItem_Query->prepare("SELECT \"userId\", \"username\" FROM \"users\" WHERE \"username\"= :user;");
    FindItem_Query->bindValue(":user", user);
    if(!FindItem_Query->exec())
    {
        qDebug() << "Unable to find item " << FindItem_Query->lastError() << FindItem_Query->lastQuery();
    }
    FindItem_Query->first();
    MainQuery->bindValue(":user", FindItem_Query->value(0).toInt());
    fldata = user;
    delete FindItem_Query;
}
void SendAlert::setSignature(qint16 signature)
{ //Бинд сигнатуры
    MainQuery->bindValue(":signature", signature);
}

void SendAlert::setDevice(QString device)
{ //Добавление информации о камере
    fldata+=device;
}

void SendAlert::AddFullLogInfo(QString info_str)
{
    fldata += " "+info_str+" ";
}
bool SendAlert::send()
{ //Отправка
    MainQuery->bindValue(":fulllog", CreateFullLog(fldata));
    if(!MainQuery->exec()) {
        qDebug() << "Unable to send alert " << MainQuery->lastError() << MainQuery->lastQuery();
        delete MainQuery;
        return false;
    }
    else
    {
        delete MainQuery;
        fldata.clear();
        return true;
    }
}

QString SendAlert::CreateFullLog(QString data)
{ //Создание строки подробной информации
   NetworkInfo ip;
   QString result;
   result=ip.GetIPAddress()+" "+QDateTime::currentDateTimeUtc().toString()+" "+data;
   return result;
}


