#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H
#include "sendalert.h"
#include <QDialog>
#include <QtSql>
#include "databaseconnection.h"
#include "buksanspy.h"
#include "checkconnection.h"
#include <QSettings>

namespace Ui {
class Authorization;
}

class Authorization : public QDialog
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = nullptr);
    ~Authorization();
CheckConnection *check;
DataBaseConnection dbConnection;
private slots:
    void on_TryLogin_Button_clicked();

    void on_ShowPassword_checkBox_stateChanged(int arg1);

private:
    Ui::Authorization *ui;
    QSqlQuery *MainQuery;
    BuksanSpy DashBoard;
    SendAlert *SendAlert_var;
    void SaveSession();

signals:





};

#endif // AUTHORIZATION_H
