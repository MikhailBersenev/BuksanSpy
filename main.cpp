#include "buksanspy.h"
#include "authorization.h"
#include "buksanspyapp.h"
#include "databaseconnection.h"
#include <QFile>
#include <QSettings>
QString username;
QStringList GetLastSessionData()
{
    QStringList result;
    QSettings *LoadSettings = BuksanSpyApp::theApp()->settings();
    LoadSettings->beginGroup("/SessionData");
    result << LoadSettings->value("/host", "").toString() << LoadSettings->value("/DBName", "").toString() << LoadSettings->value("/Port", "").toString()
           << LoadSettings->value("/UserName", "").toString() << LoadSettings->value("/UserPassword", "").toString() << LoadSettings->value("/timestamp", "").toString();
    LoadSettings->endGroup();
    delete LoadSettings;
    return result;
}
bool CheckLastSettion()
{
    const QStringList LastSessionData = GetLastSessionData();
    const int SecsPer3Days = 259200;
    const int tsDifference = QDateTime::currentSecsSinceEpoch() - LastSessionData.value(5).toInt();
    if(LastSessionData.isEmpty() or tsDifference > SecsPer3Days)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool LoadLastSession()
{
    if(!CheckLastSettion())
    {
        return false;
    }
    else
    {
        const QStringList LastSessionData = GetLastSessionData();
        DataBaseConnection dbConnection;
        if(dbConnection.CreateConnection(LastSessionData.value(0),LastSessionData.value(1),LastSessionData.value(3), LastSessionData.value(4), LastSessionData.value(2).toInt()))
        {
            username = LastSessionData.value(3);
            return true;
        }

    }
}
int main(int argc, char *argv[])
{
    BuksanSpyApp a(argc, argv, "MikhailBersenev", "BuksanSpyClient");
    Authorization auth;
    BuksanSpy w;
    QFile File("./Takezo.qss");
    File.open(QFile::ReadOnly);
    QString skin = QLatin1String(File.readAll());
    a.setStyleSheet(skin);
    if(LoadLastSession())
    {
        auth.show();
    }
    else
    {
        auth.Auth(username);
    }
    return a.exec();
}
