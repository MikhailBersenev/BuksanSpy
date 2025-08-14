#ifndef CREATEUSER_H
#define CREATEUSER_H
#include "checkstring.h"
#include "sendalert.h"
#include <QDialog>
#include <QtSql>
namespace Ui {
class CreateUser;
class SendAlert;
class CheckString;
}

class CreateUser : public QDialog
{
    Q_OBJECT

public:
    explicit CreateUser(QWidget *parent = nullptr);
    ~CreateUser();

private slots:
    void on_ShowPassword_CheckBox_stateChanged(int arg1);

    void on_Confirm_Button_clicked();

private:
    Ui::CreateUser *ui;
    QSqlQueryModel rightsModel;
    CheckString *CheckPassword;
    QSqlQuery *CreateUserQuery;
    SendAlert *SendAlert_var;




};

#endif // CREATEUSER_H
