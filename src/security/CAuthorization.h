#ifndef CAUTHORIZATION_H
#define CAUTHORIZATION_H
#include "utils/CSendAlert.h"
#include <QDialog>
#include <QtSql>
#include "database/CDatabaseConnection.h"
#include "CBuksanSpy.h"
#include "utils/CCheckConnection.h"
#include <QSettings>

namespace Ui {
class CAuthorization;
}

/**
 * @brief User authentication and authorization dialog
 * 
 * This class provides a secure login interface for the BuksanSpy surveillance system.
 * It handles user authentication, validates credentials against the database,
 * and manages user sessions. The class also includes connection checking
 * and session persistence functionality.
 * 
 * The dialog integrates with the mandatory access control system to ensure
 * proper user authorization before granting access to system functions.
 */
class CAuthorization : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the authorization dialog
     * @param parent Parent widget (default: nullptr)
     * 
     * Initializes the login interface and prepares the authentication system.
     */
    explicit CAuthorization(QWidget *parent = nullptr);
    
    /**
     * @brief Destructor for the authorization dialog
     * 
     * Cleans up resources and ensures proper session termination.
     */
    ~CAuthorization();
    
    /** @brief Connection checker for network and database connectivity */
    CCheckConnection *m_pCheck;
    
    /** @brief Database connection object for authentication queries */
    CDatabaseConnection m_dbConnection;
    
    /**
     * @brief Authenticates a user with the specified username
     * @param strUsername The username to authenticate
     * 
     * Validates user credentials and establishes a secure session
     * if authentication is successful.
     */
    void fAuth(QString strUsername);

private slots:
    /**
     * @brief Handles login button click event
     * 
     * Processes user login attempt and validates credentials
     * against the database.
     */
    void on_TryLogin_Button_clicked();
    
    /**
     * @brief Handles password visibility checkbox state change
     * @param nArg1 The new checkbox state
     * 
     * Toggles password field visibility between plain text and hidden.
     */
    void on_ShowPassword_checkBox_stateChanged(int nArg1);

private:
    /** @brief User interface object for the authorization dialog */
    Ui::CAuthorization *m_pUi;
    
    /** @brief Main SQL query object for database operations */
    QSqlQuery *m_pMainQuery;
    
    /** @brief Main application dashboard instance */
    CBuksanSpy m_dashBoard;
    
    /** @brief Alert system for logging authentication events */
    CSendAlert *m_pSendAlert;
    
    /**
     * @brief Saves the current user session to persistent storage
     * 
     * Stores session information including user credentials and
     * connection details for future use.
     */
    void fSaveSession();

signals:

};

#endif // CAUTHORIZATION_H
