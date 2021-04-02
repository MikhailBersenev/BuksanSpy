#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <QSql>
#include <QDialog>
#include "checkstring.h"
#include "sendalert.h"
#include "accessmanager.h"
namespace Ui {
class Registration;
class CheckString;
class SendAlert;
class AccessManager;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    void on_ShowPassword_CheckBox_stateChanged(int arg1);

    void on_TryToRegister_Button_clicked();

private:
    Ui::Registration *ui;
    CheckString *CheckStr_var;
    QSqlQuery *CreateUser_Query;
    SendAlert *SendAlert_var;

};

#endif // REGISTRATION_H
