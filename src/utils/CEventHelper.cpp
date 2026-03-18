#include "CEventHelper.h"
#include "../EventEngine/events/serverEvents/CInternetLostConnectionEvent.h"
#include "../EventEngine/events/serverEvents/CInternetConnectionRecoveredEvent.h"
#include "Loggerd.h"
#include <QString>

CEventHelper::CEventHelper(QObject *parent)
    : QObject(parent)
{
    LOG_TRACE_MSG("CEventHelper constructed");
    m_pEventSender = new CEventSender(this);
    m_pSQLEventEngine = new CSQLEventEngine(this);
    fInitializeEventSystem();
}

CEventHelper::~CEventHelper()
{
    LOG_TRACE_MSG("CEventHelper destroyed");
}

void CEventHelper::fInitializeEventSystem()
{
    if (m_pEventSender && m_pSQLEventEngine) {
        m_pEventSender->fAddEngine(m_pSQLEventEngine);
        LOG_INFO_MSG("Event system initialized successfully");
    } else {
        LOG_CRITICAL_MSG("Event system not initialized properly");
    }
}

void CEventHelper::fPrepareEvent(CEvent *pEvent, const QString &strUsername)
{
    if (!pEvent) {
        LOG_CRITICAL_MSG("Null event pointer in fPrepareEvent");
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
        LOG_INFO_MSG((QStringLiteral("User authentication event sent for: ") + strUsername).toStdString());
    } else {
        LOG_CRITICAL_MSG((QStringLiteral("Error sending user authentication event for: ") + strUsername).toStdString());
    }
    
    return bResult;
}

bool CEventHelper::fSendUserRegisterEvent(const QString &strUsername)
{
    CUserRegisterEvent *pEvent = new CUserRegisterEvent(this);
    fPrepareEvent(pEvent, strUsername);
    
    bool bResult = m_pEventSender->fSendEvent(pEvent);
    
    if (bResult) {
        LOG_INFO_MSG((QStringLiteral("User registration event sent for: ") + strUsername).toStdString());
    } else {
        LOG_CRITICAL_MSG((QStringLiteral("Error sending user registration event for: ") + strUsername).toStdString());
    }
    
    return bResult;
}

bool CEventHelper::fSendServerConnectEvent(const QString &strUsername)
{
    CServerConnectEvent *pEvent = new CServerConnectEvent(this);
    fPrepareEvent(pEvent, strUsername);
    
    bool bResult = m_pEventSender->fSendEvent(pEvent);
    
    if (bResult) {
        LOG_INFO_MSG((QStringLiteral("Server connection event sent for: ") + strUsername).toStdString());
    } else {
        LOG_CRITICAL_MSG((QStringLiteral("Error sending server connection event for: ") + strUsername).toStdString());
    }
    
    return bResult;
}

bool CEventHelper::fSendInternetLostConnectionEvent(const QString &strUsername)
{
    CInternetLostConnectionEvent *pEvent = new CInternetLostConnectionEvent(this);
    fPrepareEvent(pEvent, strUsername);
    
    bool bResult = m_pEventSender->fSendEvent(pEvent);
    
    if (bResult) {
        LOG_INFO_MSG((QStringLiteral("Internet lost connection event sent for: ") + strUsername).toStdString());
    } else {
        LOG_CRITICAL_MSG((QStringLiteral("Error sending internet lost connection event for: ") + strUsername).toStdString());
    }
    
    return bResult;
}

bool CEventHelper::fSendInternetConnectionRecoveredEvent(const QString &strUsername)
{
    CInternetConnectionRecoveredEvent *pEvent = new CInternetConnectionRecoveredEvent(this);
    fPrepareEvent(pEvent, strUsername);
    
    bool bResult = m_pEventSender->fSendEvent(pEvent);
    
    if (bResult) {
        LOG_INFO_MSG((QStringLiteral("Internet connection recovered event sent for: ") + strUsername).toStdString());
    } else {
        LOG_CRITICAL_MSG((QStringLiteral("Error sending internet connection recovered event for: ") + strUsername).toStdString());
    }
    
    return bResult;
}

