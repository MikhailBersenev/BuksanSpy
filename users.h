#ifndef USERS_H
#define USERS_H
#include "createuser.h"
#include "accessmanager.h"
#include <QDialog>
#include <QtSql>
#include <QtWidgets>

namespace Ui {
class Users;
class CreateUser;
}

class Users : public QDialog
{
    Q_OBJECT

public:
    explicit Users(QWidget *parent = nullptr, QString user = nullptr);
    ~Users();
    QSqlQueryModel users_model;
    CreateUser *CreateUser_var;
    QString username;
    void UpdateModels();



private slots:
    void on_AddUser_Button_clicked();

    void on_DeleteUser_Button_clicked();



    void on_users_listView_clicked(const QModelIndex &index);

private:
    Ui::Users *ui;
    QSqlQuery *MainQuery;
    AccessManager *AccessManager_var;
    void RoleAtributesParser(QString username);
    QLabel *RoleAtributeLabel;
    int RALCounter=0;

};

#endif // USERS_H
