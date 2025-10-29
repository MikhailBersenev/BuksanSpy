#ifndef CUSERCHECK_H
#define CUSERCHECK_H

#include <QtSql>
#include <QObject>

/**
 * @brief User existence checking utility class
 * 
 * This class provides functionality to check if a username already exists
 * in the database to prevent duplicate user accounts.
 */
class CUserCheck : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for the user checking utility
     * @param parent Parent object (default: nullptr)
     * 
     * Initializes the user checking system.
     */
    explicit CUserCheck(QObject *parent = nullptr);
    
    /**
     * @brief Verifies if a username already exists in the system
     * @param username The username to check
     * @return true if username exists, false otherwise
     * 
     * Queries the database to check for existing usernames to prevent
     * duplicate user accounts.
     */
    bool CheckUserExist(QString username);
    
    /** @brief Description of the last validation error encountered */
    QString ErrorDesc;

private:
    /** @brief SQL query object for database operations */
    QSqlQuery *MainQuery;

};

#endif // CUSERCHECK_H
