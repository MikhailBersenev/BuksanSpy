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
     * @brief Validates password strength and confirmation match
     * @param Password The password to validate
     * @param PasswordRpt The password confirmation/repeat
     * @return true if password meets requirements and matches confirmation, false otherwise
     * 
     * Checks password complexity requirements and ensures the confirmation
     * password matches the original password.
     */
    bool CheckPassword(QString Password, QString PasswordRpt);
    
    /**
     * @brief Checks if a string contains only valid letters
     * @param StringForCheck The string to validate
     * @return true if string contains only letters, false otherwise
     * 
     * Validates that the input string contains only alphabetic characters
     * for security and data integrity purposes.
     */
    bool CheckForLetters(QString StringForCheck);
    
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
    
    /**
     * @brief Validates email address format
     * @param email The email address to validate
     * @return true if email format is valid, false otherwise
     * 
     * Performs basic email format validation using regular expressions
     * to ensure proper email address structure.
     */
    bool CheckMail(QString email);

private:
    /** @brief SQL query object for database operations */
    QSqlQuery *MainQuery;

};

#endif // CCHECKSTRING_H
