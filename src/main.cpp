#include "CBuksanSpy.h"
#include "CAuthorization.h"
#include "CBuksanSpyApp.h"
#include "CDatabaseConnection.h"
#include <QFile>
#include <QSettings>
#include <QDateTime>
#include <QDebug>

/**
 * @brief Global username variable for the current session
 * 
 * Stores the authenticated username across the application
 * for access control and user identification purposes.
 */
QString g_strUsername;

/**
 * @brief Retrieves the last session data from application settings
 * @return QStringList containing session information [host, DBName, Port, UserName, UserPassword, timestamp]
 * 
 * Reads the previously saved session information from persistent storage
 * to enable automatic reconnection and session restoration.
 */
QStringList fGetLastSessionData()
{
    QStringList l_result;
    QSettings *l_pLoadSettings = CBuksanSpyApp::theApp()->settings();
    l_pLoadSettings->beginGroup("/SessionData");
    l_result << l_pLoadSettings->value("/host", "").toString() << l_pLoadSettings->value("/DBName", "").toString() << l_pLoadSettings->value("/Port", "").toString()
           << l_pLoadSettings->value("/UserName", "").toString() << l_pLoadSettings->value("/UserPassword", "").toString() << l_pLoadSettings->value("/timestamp", "").toString();
    l_pLoadSettings->endGroup();
    // Не удаляем l_pLoadSettings: владение у приложения (CBuksanSpyApp)
    return l_result;
}

/**
 * @brief Checks if the last session data is still valid
 * @return true if session is valid and not expired, false otherwise
 * 
 * Validates session data by checking if it exists and if the timestamp
 * is within the acceptable range (3 days). This prevents using
 * stale session information.
 */
bool fCheckLastSession()
{
    const QStringList l_lastSessionData = fGetLastSessionData();
    const int l_nSecsPer3Days = 259200;
    const int l_nTsDifference = QDateTime::currentSecsSinceEpoch() - l_lastSessionData.value(5).toInt();
    if(l_lastSessionData.isEmpty() or l_nTsDifference > l_nSecsPer3Days)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/**
 * @brief Attempts to restore the last valid session
 * @return true if session was successfully restored, false otherwise
 * 
 * Loads and validates the last session data, then attempts to establish
 * a database connection using the stored credentials. If successful,
 * sets the global username for the current session.
 */
bool fLoadLastSession()
{
    if(!fCheckLastSession())
    {
        return false;
    }
    else
    {
        const QStringList l_lastSessionData = fGetLastSessionData();
        CDatabaseConnection l_dbConnection;
        if(l_dbConnection.fCreateConnection(l_lastSessionData.value(0),l_lastSessionData.value(1),l_lastSessionData.value(3), l_lastSessionData.value(4), l_lastSessionData.value(2).toInt()))
        {
            g_strUsername = l_lastSessionData.value(3);
            qDebug() << "username " << g_strUsername << " " << l_lastSessionData.value(3);
            return true;
        }

    }
    return false;
}

/**
 * @brief Main entry point for the BuksanSpy surveillance system
 * @param argc Number of command line arguments
 * @param argv Array of command line argument strings
 * @return Application exit code
 * 
 * Initializes the Qt application, sets up the user interface,
 * attempts to restore the last session, and starts the main
 * application loop. The function handles session management,
 * user authentication, and application startup sequence.
 */
int main(int argc, char *argv[])
{
    CBuksanSpyApp l_a(argc, argv, "MikhailBersenev", "BuksanSpyClient");
    CAuthorization l_auth;
    CBuksanSpy l_w;
    QFile l_file("./Takezo.qss");
    if (l_file.open(QFile::ReadOnly)) {
        const QString l_strSkin = QLatin1String(l_file.readAll());
        l_a.setStyleSheet(l_strSkin);
    } else {
        qWarning() << "Stylesheet not found, running without theme";
    }
    if(!fLoadLastSession())
    {
        l_auth.show();
    }
    else
    {
        l_auth.fAuth(g_strUsername);
    }
    return l_a.exec();
}
