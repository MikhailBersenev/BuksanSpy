#include "CSQLEventEngine.h"

#include <QSqlError>
#include <QDebug>
#include <QVariant>
#include <QDateTime>

CSQLEventEngine::CSQLEventEngine(QObject *parent)
    : CEventEngine{parent}
{

}

bool CSQLEventEngine::fSend(CEvent *pEvent)
{
    QString strHostName  = pEvent->fGetHostName();
    QString strTimeStamp = QString::number(pEvent->fGetTimeStamp());
    QString strUserName = pEvent->fGetUserName();
    QString strFullLog = pEvent->fGetFullLog();
    CEvent::nSignature nSignature = pEvent->fGetSignature();
    QTime time = pEvent->fGetTime();
    QDate date = pEvent->fGetDate();
    this->fPrepare(strHostName, strTimeStamp, time, date);
    this->fSetUser(strUserName);
    this->fSetSignature(nSignature);
    if(!this->fPost(strHostName, strFullLog)) {
        qDebug() << "Unable to send event";
        return false;
    }
    return true;
}

QString CSQLEventEngine::fGetNameString()
{
    return "CSQLEventEngine";
}

void CSQLEventEngine::fPrepare(QString& lStrHostName, QString& lStrTimeStamp, QTime& lTime, QDate& lDate)
{
    m_MainQuery.prepare("INSERT INTO events.alerts (\"user\", time, date, unixtime, signature, host, \"fullLog\")"
                       " VALUES (:user, :time, :date, :unixtime, :signature, :host, :fulllog);");
    m_MainQuery.bindValue(":host", lStrHostName);
    m_MainQuery.bindValue(":unixtime", lStrTimeStamp);
    m_MainQuery.bindValue(":time", lTime);
    m_MainQuery.bindValue(":date", lDate);
}
void CSQLEventEngine::fSetUser(QString& strUser)
{
    m_FindItemQuery.prepare("SELECT \"userId\" FROM mrbac.users WHERE username = :username;");
    m_FindItemQuery.bindValue(":username", strUser);
    if(!m_FindItemQuery.exec())
    {
        qDebug() << "Unable to find user" << m_FindItemQuery.lastError() << m_FindItemQuery.lastQuery();
        return;
    }
    m_FindItemQuery.first();
    m_MainQuery.bindValue(":user", m_FindItemQuery.value(0).toInt());
    m_strFullData += strUser;
}
void CSQLEventEngine::fSetSignature(CEvent::nSignature& nSignature)
{
    QVariant Signature = static_cast <qint16>(nSignature);
    m_MainQuery.bindValue(":signature", Signature);

}
void CSQLEventEngine::fAddFullLogInfo(QString& strInfo)
{
    m_strFullData += " " + strInfo + " ";
}
bool CSQLEventEngine::fPost(QString& lStrHostName, QString& lStrFullLog)
{
    m_MainQuery.bindValue(":fulllog", lStrFullLog);
    if(!m_MainQuery.exec())
    {
        qDebug() << "Unable to send alert" <<  m_MainQuery.lastError() <<  m_MainQuery.lastQuery();
        return false;
    }
    else
    {
        return true;
    }
}

QString CSQLEventEngine::fCreateFullLog(QString& strData, QString& lStrHostName)
{
    QString l_strResult;
    l_strResult = lStrHostName + " " + QDateTime::currentDateTimeUtc().toString() + " " + strData;
    return l_strResult;
}
