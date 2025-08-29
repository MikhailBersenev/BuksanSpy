#ifndef CDATABASECONNECTION_H
#define CDATABASECONNECTION_H
#include <QtSql>
#include <QObject>

class CSendAlert;
/**
 * @brief Database connection and management class
 * 
 * This class handles all database connectivity operations for the BuksanSpy system.
 * It manages database connections, connection parameters, and provides a centralized
 * interface for database operations across the application.
 * 
 * The class supports PostgreSQL database connections and includes automatic
 * alert logging for connection events and database operations.
 */
class CDatabaseConnection : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for the database connection manager
     * @param parent Parent object (default: nullptr)
     * 
     * Initializes the database connection system and prepares
     * the alert system for connection event logging.
     */
    explicit CDatabaseConnection(QObject *parent = nullptr);
    
    /**
     * @brief Establishes a database connection with the specified parameters
     * @param strHostName Database server hostname or IP address
     * @param strDBName Name of the database to connect to
     * @param strUserName Database username for authentication
     * @param strPassword Database password for authentication
     * @param nPort Database server port number
     * @return true if connection was successful, false otherwise
     * 
     * Creates and establishes a database connection using the provided
     * credentials and connection parameters. Automatically logs connection
     * events through the alert system.
     */
    bool fCreateConnection(QString strHostName, QString strDBName, QString strUserName, QString strPassword, int nPort);
    
    /** @brief Qt SQL database object for database operations */
    QSqlDatabase m_db;
    
    /** @brief Alert system for logging database connection events */
    CSendAlert *m_pSendAlert;

private slots:

signals:

};

#endif // CDATABASECONNECTION_H
