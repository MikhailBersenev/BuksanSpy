#ifndef CDATABASECONNECTIONPSQL_H
#define CDATABASECONNECTIONPSQL_H

#include "CDatabaseConnection.h"

// class CSendAlert; // Временно закомментировано
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
class CDatabaseConnectionPSQL : public CDatabaseConnection
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
    explicit CDatabaseConnectionPSQL(QObject *parent = nullptr);
    
    /**
     * @brief Establishes a database connection with the specified parameters
     * @param lConnection Database connection parameters structure
     * @return true if connection was successful, false otherwise
     * 
     * Creates and establishes a database connection using the provided
     * credentials and connection parameters. Automatically logs connection
     * events through the alert system.
     */
    bool fCreateConnection(SDBConnection& lConnection) override;
    
    // /** @brief Alert system for logging database connection events */
    // CSendAlert *m_pSendAlert; // Временно закомментировано

private slots:

signals:

};

#endif // CDATABASECONNECTIONPSQL_H
