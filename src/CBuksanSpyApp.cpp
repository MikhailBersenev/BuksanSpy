#include "CBuksanSpyApp.h"

CBuksanSpyApp::CBuksanSpyApp(int& argc, char** argv, const QString& strCompany, const QString& strAppName)
    : QApplication(argc, argv), m_pSettings(0)
{
    setOrganizationName(strCompany);
    setApplicationName(strAppName);
    m_pSettings = new QSettings(strCompany, strAppName, this);
}

CBuksanSpyApp *CBuksanSpyApp::theApp()
{
    return (CBuksanSpyApp*)qApp;
}

QSettings *CBuksanSpyApp::settings()
{
    return m_pSettings;
}
