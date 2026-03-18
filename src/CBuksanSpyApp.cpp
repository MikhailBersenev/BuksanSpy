#include "CBuksanSpyApp.h"
#include "Loggerd.h"
#include <QString>

CBuksanSpyApp::CBuksanSpyApp(int& argc, char** argv, const QString& strCompany, const QString& strAppName)
    : QApplication(argc, argv), m_pSettings(0)
{
    setOrganizationName(strCompany);
    setApplicationName(strAppName);
    m_pSettings = new QSettings(strCompany, strAppName, this);
    LOG_INFO_MSG((QStringLiteral("CBuksanSpyApp: organization=") + strCompany + QLatin1String(" app=") + strAppName).toStdString());
}

CBuksanSpyApp *CBuksanSpyApp::theApp()
{
    return (CBuksanSpyApp*)qApp;
}

QSettings *CBuksanSpyApp::settings()
{
    return m_pSettings;
}
