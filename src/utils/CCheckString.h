#ifndef CCHECKSTRING_H
#define CCHECKSTRING_H
#include <QtSql>
#include <QObject>
#include <QRegularExpression>

/**
 * @brief String validation and security checking utility class
 * 
 * This class provides comprehensive string validation functionality for the
 * BuksanSpy system, including password strength checking, user input validation,
 * and security policy enforcement. It ensures data integrity and security
 * compliance across the application.
 * 
 * The class implements various validation algorithms for passwords, usernames,
 * email addresses, and other user inputs to maintain system security standards.
 */
class CCheckString : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for the string validation utility
     * @param parent Parent object (default: nullptr)
     * 
     * Initializes the validation system and prepares the database
     * connection for user existence checks.
     */
    explicit CCheckString(QObject *parent = nullptr);
    
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

#endif // CCHECKSTRING_H
