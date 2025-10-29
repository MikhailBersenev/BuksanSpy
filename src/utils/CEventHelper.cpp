#include "CEventHelper.h"
#include "../EventEngine/events/serverEvents/CInternetLostConnectionEvent.h"
#include "../EventEngine/events/serverEvents/CInternetConnectionRecoveredEvent.h"
#include <QDebug>

CEventHelper::CEventHelper(QObject *parent)
    : QObject(parent)
{
    m_pEventSender = new CEventSender(this);
    m_pSQLEventEngine = new CSQLEventEngine(this);
    fInitializeEventSystem();
}

CEventHelper::~CEventHelper()
{
    // Удаление происходит автоматически через parent
}

void CEventHelper::fInitializeEventSystem()
{
    if (m_pEventSender && m_pSQLEventEngine) {
        m_pEventSender->fAddEngine(m_pSQLEventEngine);
        qDebug() << "Event system initialized successfully";
    } else {
        qDebug() << "Error: Event system not initialized properly";
    }
}

void CEventHelper::fPrepareEvent(CEvent *pEvent, const QString &strUsername)
{
    if (!pEvent) {
        qDebug() << "Error: Null event pointer";
        return;
    }
    
    // Установка имени пользователя
    QString l_strUser = strUsername;
    pEvent->fSetUserName(l_strUser);
    
    // Установка IP адреса
    QString l_strHostName = m_networkInfo.fGetIPAddress();
    pEvent->fSetHostName(l_strHostName);
}

bool CEventHelper::fSendUserAuthEvent(const QString &strUsername)
{
    CUserAuthEvent *pEvent = new CUserAuthEvent(this);
    fPrepareEvent(pEvent, strUsername);
    
    bool bResult = m_pEventSender->fSendEvent(pEvent);
    
    if (bResult) {
        qDebug() << "User authentication event sent for:" << strUsername;
    } else {
        qDebug() << "Error sending user authentication event";
    }
    
    return bResult;
}

bool CEventHelper::fSendUserRegisterEvent(const QString &strUsername)
{
    CUserRegisterEvent *pEvent = new CUserRegisterEvent(this);
    fPrepareEvent(pEvent, strUsername);
    
    bool bResult = m_pEventSender->fSendEvent(pEvent);
    
    if (bResult) {
        qDebug() << "User registration event sent for:" << strUsername;
    } else {
        qDebug() << "Error sending user registration event";
    }
    
    return bResult;
}

bool CEventHelper::fSendServerConnectEvent(const QString &strUsername)
{
    CServerConnectEvent *pEvent = new CServerConnectEvent(this);
    fPrepareEvent(pEvent, strUsername);
    
    bool bResult = m_pEventSender->fSendEvent(pEvent);
    
    if (bResult) {
        qDebug() << "Server connection event sent for:" << strUsername;
    } else {
        qDebug() << "Error sending server connection event";
    }
    
    return bResult;
}

bool CEventHelper::fSendInternetLostConnectionEvent(const QString &strUsername)
{
    CInternetLostConnectionEvent *pEvent = new CInternetLostConnectionEvent(this);
    fPrepareEvent(pEvent, strUsername);
    
    bool bResult = m_pEventSender->fSendEvent(pEvent);
    
    if (bResult) {
        qDebug() << "Internet lost connection event sent for:" << strUsername;
    } else {
        qDebug() << "Error sending internet lost connection event";
    }
    
    return bResult;
}

bool CEventHelper::fSendInternetConnectionRecoveredEvent(const QString &strUsername)
{
    CInternetConnectionRecoveredEvent *pEvent = new CInternetConnectionRecoveredEvent(this);
    fPrepareEvent(pEvent, strUsername);
    
    bool bResult = m_pEventSender->fSendEvent(pEvent);
    
    if (bResult) {
        qDebug() << "Internet connection recovered event sent for:" << strUsername;
    } else {
        qDebug() << "Error sending internet connection recovered event";
    }
    
    return bResult;
}

