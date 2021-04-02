#ifndef USERS_H
#define USERS_H
#include "createuser.h"
#include "accessmanager.h"
#include <QDialog>
#include <QtSql>

namespace Ui {
class Users;
class CreateUser;
}

class Users : public QDialog
{
    Q_OBJECT

public:
    explicit Users(QWidget *parent = nullptr);
    ~Users();
    QSqlQueryModel users_model;
    CreateUser *CreateUser_var;
    QString username;


private slots:
    void on_AddUser_Button_clicked();

    void on_DeleteUser_Button_clicked();
    void UpdateModels();

private:
    Ui::Users *ui;
    QSqlQuery *MainQuery;
    AccessManager *AccessManager_var;
};

#endif // USERS_H
