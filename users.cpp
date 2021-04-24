#include "users.h"
#include "ui_users.h"
#include <QtWidgets>


Users::Users(QWidget *parent, QString user) :
    QDialog(parent),
    ui(new Ui::Users)
{
    ui->setupUi(this);
    username = user;
    UpdateModels();




}

Users::~Users()
{
    delete ui;

}

void Users::setUsername(const QString& value)
{
    username = value;

}


void Users::on_AddUser_Button_clicked()
{
    CreateUser_var = new CreateUser; //показываем форму
    CreateUser_var->exec();
    delete CreateUser_var;
}

void Users::on_DeleteUser_Button_clicked()
{

    AccessManager_var = new AccessManager(this);
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Удаление пользователя", "Вы уверены, что хотите удалить пользователя? \n ВНИМАНИЕ! Удаление пользователя приведет к "
                                                                 "удалению всех связанных с ним данных", QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::No)
    {
        return;
    }
    else
    {

        MainQuery = new QSqlQuery;
        MainQuery->prepare("DELETE FROM users WHERE username = :current;");
        MainQuery->bindValue(":current", users_model.data(users_model.index(ui->users_listView->currentIndex().row(),0)).toString());
        if(!MainQuery->exec() || users_model.query().value(0).toString()==username)
        {
            qDebug() << "Unable to delete user" << MainQuery->lastError() << MainQuery->lastQuery();
            QMessageBox::critical(this, "Ошибка", "Не удалось удалить пользователя");
            return;
        }
        else
        {
            QMessageBox::information(this, "Пользователи и группы", "Пользователь удален");
            UpdateModels();


        }
    }
}

void Users::UpdateModels()
{
   AccessManager_var = new AccessManager(this);
    users_model.query().bindValue(":macm", 0);
//    AccessManager_var->GetAccessLevel(username)
    users_model.setQuery("SELECT  * FROM \"vUsers\" WHERE \"accessLevel\" >="+QString::number(AccessManager_var->GetAccessLevel(username))+";");
    ui->users_listView->setModel(&users_model);
    ui->users_listView->setModelColumn(1);
   qDebug() << AccessManager_var->GetAccessLevel(username) << username;
    delete  AccessManager_var;
}




void Users::on_users_listView_clicked(const QModelIndex &index)
{
    Q_UNUSED(index)
    ui->mandatorygroup_label_2->setText(users_model.data(users_model.index(ui->users_listView->currentIndex().row(),3)).toString());
    ui->registrationdate_label_2->setText(users_model.data(users_model.index(ui->users_listView->currentIndex().row(),2)).toString());
    ui->macm_label_2->setText(users_model.data(users_model.index(ui->users_listView->currentIndex().row(),5)).toString());
}
