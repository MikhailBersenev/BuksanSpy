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
    MainQuery->prepare("INSERT INTO alerts (\"user\", time, date, unixtime, signature, host, device)"
                       " VALUES (:user, :time, :date, :unixtime, :signature, :host, 25);");
    MainQuery->bindValue(":time", QTime::currentTime());
    MainQuery->bindValue(":date", QDate::currentDate());
    MainQuery->bindValue(":host", ip.GetIPAddress());
    MainQuery->bindValue(":unixtime", QDateTime::currentSecsSinceEpoch());
}
void SendAlert::setUser(QString user)
{
    FindItem_Query = new QSqlQuery;
    FindItem_Query->prepare("SELECT \"userId\", \"username\" FROM \"users\" WHERE \"username\"= :user;");
    FindItem_Query->bindValue(":user", user);
    if(!FindItem_Query->exec())
    {
        qDebug() << "Unable to find item " << FindItem_Query->lastError() << FindItem_Query->lastQuery();
    }
    FindItem_Query->first();
    MainQuery->bindValue(":user", FindItem_Query->value(0).toInt());
    delete FindItem_Query;
}
void SendAlert::setSignature(qint16 signature)
{
    MainQuery->bindValue(":signature", signature);
}
bool SendAlert::send()
{
    if(!MainQuery->exec()) {
        qDebug() << "Unable to send alert " << MainQuery->lastError() << MainQuery->lastQuery();
        delete MainQuery;
        return false;
    }
    else
    {
        delete MainQuery;
        return true;
    }
}
