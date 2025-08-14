#include "networkinfo.h"
#include <QHostAddress>
#include <QNetworkInterface>
NetworkInfo::NetworkInfo(QObject *parent) : QObject(parent)
{

}

QString NetworkInfo::GetIPAddress() //Получение местного IP
{
    QString result;
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
            result = address.toString();
    }
    return result;
}




