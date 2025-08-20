#include "CSendAlert.h"
#include "CNetworkInfo.h"
#include <QDateTime>
#include <QDebug>

CSendAlert::CSendAlert(QObject *parent) : QObject(parent)
{

}

void CSendAlert::fPrepare()
{
    m_pMainQuery = new QSqlQuery;
    m_pMainQuery->prepare("INSERT INTO alerts (host, timestamp, user, signature, device, fulllog) VALUES (:host, :timestamp, :user, :signature, :device, :fulllog);");
    CNetworkInfo l_ip;
    m_pMainQuery->bindValue(":host", l_ip.fGetIPAddress());
    m_pMainQuery->bindValue(":timestamp", QDateTime::currentDateTimeUtc());
}

void CSendAlert::fSetUser(QString strUser)
{
    m_pFindItemQuery = new QSqlQuery;
    m_pFindItemQuery->prepare("SELECT \"userId\" FROM users WHERE username = :username;");
    m_pFindItemQuery->bindValue(":username", strUser);
    if(!m_pFindItemQuery->exec())
    {
        qDebug() << "Unable to find user" << m_pFindItemQuery->lastError() << m_pFindItemQuery->lastQuery();
        return;
    }
    m_pFindItemQuery->first();
    m_pMainQuery->bindValue(":user", m_pFindItemQuery->value(0).toInt());
    m_strFullData = strUser;
    delete m_pFindItemQuery;
}

void CSendAlert::fSetSignature(qint16 nSignature)
{
    m_pMainQuery->bindValue(":signature", nSignature);
}

void CSendAlert::fSetDevice(QString strDevice)
{
    m_strFullData += strDevice;
}

void CSendAlert::fAddFullLogInfo(QString strInfo)
{
    m_strFullData += " " + strInfo + " ";
}

bool CSendAlert::fSend()
{
    m_pMainQuery->bindValue(":fulllog", fCreateFullLog(m_strFullData));
    if(!m_pMainQuery->exec())
    {
        qDebug() << "Unable to send alert" << m_pMainQuery->lastError() << m_pMainQuery->lastQuery();
        delete m_pMainQuery;
        return false;
    }
    else
    {
        delete m_pMainQuery;
        return true;
    }
}

QString CSendAlert::fCreateFullLog(QString strData)
{
   CNetworkInfo l_ip;
   QString l_strResult;
   l_strResult = l_ip.fGetIPAddress() + " " + QDateTime::currentDateTimeUtc().toString() + " " + strData;
   return l_strResult;
}


