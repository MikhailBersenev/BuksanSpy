#ifndef CSENDALERT_H
#define CSENDALERT_H
#include <QtSql>
#include <QMainWindow>
#include <QObject>
#include <QTime>
#include <QDate>
#include <QDateTime>

/**
 * @brief System alert and logging manager
 * 
 * This class handles the creation, formatting, and transmission of system alerts
 * and log entries for the BuksanSpy surveillance system. It provides a centralized
 * mechanism for recording system events, user actions, and security incidents.
 * 
 * The alert system supports structured logging with user identification,
 * device information, and detailed event descriptions. All alerts are stored
 * in the database for audit and monitoring purposes.
 */
class CSendAlert : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for the alert manager
     * @param parent Parent object (default: nullptr)
     * 
     * Initializes the alert system and prepares the database
     * connection for logging operations.
     */
    explicit CSendAlert(QObject *parent = nullptr);
    
    /**
     * @brief Prepares the alert system for logging
     * 
     * Initializes the SQL query and sets up basic alert parameters
     * including timestamp and host information.
     */
    void fPrepare();
    
    /**
     * @brief Sets the user associated with the alert
     * @param strUser The username to associate with the alert
     * 
     * Links the alert to a specific user for accountability
     * and audit trail purposes.
     */
    void fSetUser(QString strUser);
    
    /**
     * @brief Sets the alert signature/type identifier
     * @param nSignature The numeric signature identifying the alert type
     * 
     * Assigns a category identifier to the alert for proper
     * classification and filtering.
     */
    void fSetSignature(qint16 nSignature);
    
    /**
     * @brief Sets the device information for the alert
     * @param strDevice The device identifier or description
     * 
     * Associates the alert with a specific surveillance device
     * or system component.
     */
    void fSetDevice(QString strDevice);
    
    /**
     * @brief Adds additional information to the alert log
     * @param strInfo Additional information to include in the alert
     * 
     * Appends supplementary details to the alert entry for
     * comprehensive event documentation.
     */
    void fAddFullLogInfo(QString strInfo);
    
    /**
     * @brief Sends the alert to the database
     * @return true if the alert was successfully logged, false otherwise
     * 
     * Transmits the complete alert information to the database
     * for permanent storage and retrieval.
     */
    bool fSend();

private:
    /** @brief Main SQL query object for alert operations */
    QSqlQuery *m_pMainQuery;
    
    /** @brief SQL query object for finding user information */
    QSqlQuery *m_pFindItemQuery;
    
    /**
     * @brief Creates a formatted log entry with timestamp and metadata
     * @param strData The raw data to format
     * @return Formatted log string with timestamp and system information
     * 
     * Generates a structured log entry including timestamp, IP address,
     * and formatted event data.
     */
    QString fCreateFullLog(QString strData);
    
    /** @brief Accumulated log data for the current alert */
    QString m_strFullData;

signals:

};

#endif // CSENDALERT_H
