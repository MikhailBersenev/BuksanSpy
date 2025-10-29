#ifndef CEVENTHELPER_H
#define CEVENTHELPER_H

#include <QObject>
#include "../EventEngine/CEventSender.h"
#include "../EventEngine/CSQLEventEngine.h"
#include "../EventEngine/events/securityEvents/CUserAuthEvent.h"
#include "../EventEngine/events/securityEvents/CUserRegisterEvent.h"
#include "../EventEngine/events/serverEvents/CServerConnectEvent.h"
#include "CNetworkInfo.h"

/**
 * @brief Helper class for working with event system
 * 
 * This class provides convenient methods for creating and sending events
 * in the BuksanSpy system. It initializes the event engine and provides
 * simple API for logging security and system events.
 */
class CEventHelper : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the event helper
     * @param parent Parent object (default: nullptr)
     * 
     * Initializes the event system with SQL engine for database logging.
     */
    explicit CEventHelper(QObject *parent = nullptr);
    
    /**
     * @brief Destructor for the event helper
     */
    ~CEventHelper();
    
    /**
     * @brief Sends a user authentication event
     * @param strUsername Username of the authenticated user
     * @return true if event was sent successfully, false otherwise
     */
    bool fSendUserAuthEvent(const QString &strUsername);
    
    /**
     * @brief Sends a user registration event
     * @param strUsername Username of the newly registered user
     * @return true if event was sent successfully, false otherwise
     */
    bool fSendUserRegisterEvent(const QString &strUsername);
    
    /**
     * @brief Sends a server connection event
     * @param strUsername Username used for connection
     * @return true if event was sent successfully, false otherwise
     */
    bool fSendServerConnectEvent(const QString &strUsername);
    
    /**
     * @brief Sends an internet lost connection event
     * @param strUsername Username associated with the event
     * @return true if event was sent successfully, false otherwise
     */
    bool fSendInternetLostConnectionEvent(const QString &strUsername);
    
    /**
     * @brief Sends an internet connection recovered event
     * @param strUsername Username associated with the event
     * @return true if event was sent successfully, false otherwise
     */
    bool fSendInternetConnectionRecoveredEvent(const QString &strUsername);

private:
    /** @brief Event sender for transmitting events */
    CEventSender *m_pEventSender;
    
    /** @brief SQL event engine for database logging */
    CSQLEventEngine *m_pSQLEventEngine;
    
    /** @brief Network info for getting IP address */
    CNetworkInfo m_networkInfo;
    
    /**
     * @brief Initializes the event system
     * 
     * Sets up the SQL event engine and adds it to the event sender.
     */
    void fInitializeEventSystem();
    
    /**
     * @brief Prepares an event with user and host information
     * @param pEvent Pointer to the event to prepare
     * @param strUsername Username to associate with the event
     */
    void fPrepareEvent(CEvent *pEvent, const QString &strUsername);
};

#endif // CEVENTHELPER_H

