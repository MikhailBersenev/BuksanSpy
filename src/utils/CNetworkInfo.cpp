#include "CNetworkInfo.h"
#include "Loggerd.h"
#include <QHostAddress>
#include <QNetworkInterface>
#include <QString>

CNetworkInfo::CNetworkInfo(QObject *parent) : QObject(parent)
{
    LOG_TRACE_MSG("CNetworkInfo constructed");
}

QString CNetworkInfo::fGetIPAddress() //Получение местного IP
{
    QString l_strResult;
    const QHostAddress &l_localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &l_address: QNetworkInterface::allAddresses()) {
        if (l_address.protocol() == QAbstractSocket::IPv4Protocol && l_address != l_localhost)
            l_strResult = l_address.toString();
    }
    LOG_TRACE_MSG((QStringLiteral("CNetworkInfo::fGetIPAddress ") + l_strResult).toStdString());
    return l_strResult;
}




