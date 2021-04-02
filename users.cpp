#include "users.h"
#include "ui_users.h"
#include <QtWidgets>


Users::Users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Users)
{
    ui->setupUi(this);
    UpdateModels();


}

Users::~Users()
{
    delete ui;
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
        MainQuery->prepare("DELETE FROM users WHERE \"userId\" = :current;");
        MainQuery->bindValue(":current", users_model.data(users_model.index(ui->users_Table->currentIndex().row(),0)).toString());
        if(!MainQuery->exec())
        {
            qDebug() << "Unable to delete user" << MainQuery->lastError() << MainQuery->lastQuery();
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
    int i=0;
    QVariantList headers_list;
    headers_list << "Имя пользователя" << "Дата регистрации" << "E-mail адрес" << "Активен(Не заблокирован)" << "Мандатная группа";
    users_model.setQuery("SELECT  * FROM \"vUsers\";");
    users_model.removeColumn(0);
    foreach(headers_list.value(i), headers_list)
    {
      users_model.setHeaderData(i, Qt::Horizontal, headers_list.value(i));
      i++;
    }


    ui->users_Table->setModel(&users_model);
}
