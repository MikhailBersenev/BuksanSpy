#ifndef BUKSANSPYAPP_H
#define BUKSANSPYAPP_H
#include <QApplication>
#include <QSettings>

class BuksanSpyApp : public QApplication
{
private:
    QSettings *p_settings;
public:
    BuksanSpyApp(int& argc, char** argv, const QString& Company, const QString& AppName);
    static BuksanSpyApp* theApp();
    QSettings* settings();

};

#endif // BUKSANSPYAPP_H
