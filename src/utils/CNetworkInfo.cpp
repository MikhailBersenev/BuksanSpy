#include "CNetworkInfo.h"
#include <QHostAddress>
#include <QNetworkInterface>

CNetworkInfo::CNetworkInfo(QObject *parent) : QObject(parent)
{

}

QString CNetworkInfo::fGetIPAddress() //Получение местного IP
{
    QString l_strResult;
    const QHostAddress &l_localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &l_address: QNetworkInterface::allAddresses()) {
        if (l_address.protocol() == QAbstractSocket::IPv4Protocol && l_address != l_localhost)
            l_strResult = l_address.toString();
    }
    return l_strResult;
}




