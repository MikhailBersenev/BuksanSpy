#include "CEvent.h"

CEvent::CEvent(QObject *parent)
    : QObject{parent}
{
    m_time = QTime::currentTime();
    m_date = QDate::currentDate();
    m_nTimeStamp = QDateTime::currentSecsSinceEpoch();
    m_strFullLog += m_strHostName + " " + QDateTime::currentDateTimeUtc().toString() + " ";

}

CEvent::CEvent(CEvent *pEvent)
{
    if(pEvent) {
        m_strUserName = pEvent->fGetUserName();
        m_time = pEvent->fGetTime();
        m_date = pEvent->fGetDate();
        m_nTimeStamp = pEvent->fGetTimeStamp();
        m_strHostName = pEvent->fGetHostName();
        m_strFullLog = pEvent->fGetFullLog();
        m_nSignature = pEvent->fGetSignature();
        m_nSignatureType = fGetType();
    }
}

QString CEvent::fGetUserName()
{
    return m_strUserName;
}

QTime CEvent::fGetTime()
{
    return m_time;
}

QDate CEvent::fGetDate()
{
    return m_date;
}

qint64 CEvent::fGetTimeStamp()
{
    return m_nTimeStamp;
}

QString CEvent::fGetHostName()
{
    return m_strHostName;
}

QString CEvent::fGetFullLog()
{
    return m_strFullLog;
}

void CEvent::fSetUserName(QString &lStrUserName)
{
    m_strUserName = lStrUserName;
    m_strFullLog += " " + m_strUserName + " ";
}

void CEvent::fSetHostName(QString &lStrHostName)
{
    m_strHostName = lStrHostName;
}

CEvent::nSignature CEvent::fGetSignature()
{
    return m_nSignature;
}

CEvent::nSignatureType CEvent::fGetType()
{
    return m_nSignatureType;
}
