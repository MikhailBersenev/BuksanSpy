#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H
#include "sendalert.h"
#include <QDialog>
#include <QtSql>
#include "setupconnection.h"
#include "buksanspy.h"
#include "registration.h"

namespace Ui {
class Authorization;
}

class Authorization : public QDialog
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = nullptr);
    ~Authorization();

private slots:
    void on_GoToSetupConnection_Button_clicked();

    void on_TryLogin_Button_clicked();

    void on_GotToRegistration_Button_clicked();

    void on_quit_Button_clicked();
    void attempts_expired();

private:
    Ui::Authorization *ui;
    SetupConnection SetupConnection_var;
    QSqlQuery *MainQuery;
    BuksanSpy DashBoard;
    SendAlert *SendAlert_var;
    Registration Registration_var;
    int Counter;
signals:
    void expired();





};

#endif // AUTHORIZATION_H
