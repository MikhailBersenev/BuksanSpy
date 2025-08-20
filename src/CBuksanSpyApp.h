#ifndef CBUKSANSPYAPP_H
#define CBUKSANSPYAPP_H
#include <QApplication>
#include <QSettings>

class CBuksanSpyApp : public QApplication
{
private:
    QSettings *m_pSettings;

public:
    CBuksanSpyApp(int& argc, char** argv, const QString& strCompany, const QString& strAppName);
    static CBuksanSpyApp* theApp();
    QSettings* settings();
};

#endif // CBUKSANSPYAPP_H
