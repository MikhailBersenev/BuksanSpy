#include "buksanspyapp.h"

BuksanSpyApp::BuksanSpyApp(int& argc, char** argv, const QString& Company, const QString& AppName
                           ): QApplication(argc, argv), p_settings(0)
{
setOrganizationName(Company);
setApplicationName(AppName);
p_settings = new QSettings(Company, AppName, this);
}

BuksanSpyApp *BuksanSpyApp::theApp()
{
    return (BuksanSpyApp*)qApp;
}

QSettings *BuksanSpyApp::settings()
{
    return p_settings;
}
