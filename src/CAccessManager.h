#ifndef CACCESSMANAGER_H
#define CACCESSMANAGER_H
#include <QObject>
#include <QtSql>

/**
 * @brief Mandatory Access Control (MAC) manager for user rights and permissions
 * 
 * This class implements a comprehensive access control system that manages
 * user permissions, mandatory access levels, and security policies for the
 * BuksanSpy surveillance system. It provides centralized control over
 * user access to various system functions and resources.
 * 
 * The access manager enforces security policies based on user roles,
 * mandatory access levels, and specific function permissions. It integrates
 * with the database to retrieve and validate user rights in real-time.
 */
class CAccessManager : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for the access manager
     * @param parent Parent object (default: nullptr)
     * 
     * Initializes the access control system and prepares the database
     * connection for rights validation.
     */
    explicit CAccessManager(QObject *parent = nullptr);
    
    /**
     * @brief Checks if a user has a specific right
     * @param strUsername The username to check
     * @param nRight The right identifier to validate
     * @return true if the user has the right, false otherwise
     * 
     * Validates user permissions for specific system functions
     * based on their role and access level.
     */
    bool fCheckRight(QString strUsername, int nRight);
    
    /**
     * @brief Retrieves the mandatory access group for a user
     * @param strUsername The username to query
     * @return The mandatory access group name as a string
     * 
     * Returns the security classification level assigned to the user
     * for mandatory access control purposes.
     */
    QString fGetMandatoryGroup(QString strUsername);
    
    /**
     * @brief Gets the access level for a specific user
     * @param strUsername The username to query
     * @return The numeric access level (higher values indicate more privileges)
     * 
     * Returns the user's access level which determines their overall
     * system privileges and capabilities.
     */
    qint64 fGetAccessLevel(QString strUsername);

private:
    /** @brief SQL query object for database operations */
    QSqlQuery *m_pMainQuery;

signals:

};

#endif // CACCESSMANAGER_H
