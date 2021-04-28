#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H
#include "sendalert.h"
#include <QDialog>
#include <QtSql>
#include "databaseconnection.h"
#include "buksanspy.h"
#include "checkconnection.h"

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
private slots:
    void on_TryLogin_Button_clicked();

private:
    Ui::Authorization *ui;
    QSqlQuery *MainQuery;
    BuksanSpy DashBoard;
    SendAlert *SendAlert_var;
signals:





};

#endif // AUTHORIZATION_H
