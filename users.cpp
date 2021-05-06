#include "users.h"
#include "ui_users.h"
#include <QtWidgets>
#include "mandatorymarkseditor.h"
#include "mandatorygroups.h"

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
        if(!MainQuery->exec() || users_model.query().value(1).toString()==username)
        {
            qDebug() << "Unable to delete user" << MainQuery->lastError() << MainQuery->lastQuery();
            QMessageBox::critical(this, "Ошибка", "Не удалось удалить пользователя");
            return;
        }
        if(!MainQuery->exec("DROP ROLE "+users_model.data(users_model.index(ui->users_listView->currentIndex().row(),1)).toString()+";"))
        {
            qDebug() << "Unable to delete user" << MainQuery->lastError() << MainQuery->lastQuery();
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
    users_model.setQuery("SELECT  * FROM \"vUsers\" WHERE \"accessLevel\" >="+QString::number(AccessManager_var->GetAccessLevel(username))+";");
    ui->users_listView->setModel(&users_model);
    ui->users_listView->setModelColumn(1);
    qDebug() << AccessManager_var->GetAccessLevel(username) << username;
    delete  AccessManager_var;
}




void Users::on_users_listView_clicked(const QModelIndex &index)
{
    Q_UNUSED(index)
    addActions({ui->ChangePassword_action});
    ui->mandatorygroup_label_2->setText(users_model.data(users_model.index(ui->users_listView->currentIndex().row(),3)).toString());
    ui->registrationdate_label_2->setText(users_model.data(users_model.index(ui->users_listView->currentIndex().row(),2)).toString());
    ui->macm_label_2->setText(users_model.data(users_model.index(ui->users_listView->currentIndex().row(),4)).toString());
    RoleAtributesParser(users_model.data(users_model.index(ui->users_listView->currentIndex().row(),1)).toString());
}

void Users::RoleAtributesParser(QString username)
{
    MainQuery = new QSqlQuery;
    QStringList list;
    list << "Управление пользователями и группами" << "Добавление устройств" << "Редактирование устройств" << "Удаление устройств" << "Просмотр журнала событий" << "Очистка журнала событий" << "Просмотр настроек ПС" << "Изменение настроек ПС" << "Просмотр журнала видеозаписей" << "Выгрузка видеозаписей в файл" << "Удаление видеозаписей";
    if(RALCounter!=0)
    {
        ui->RoleAtributes_listWidget->clear();
        RALCounter=0;
    }
    const QString SQLQuery = "SELECT users.username, rights.\"usersControl\", rights.\"addDevice\", rights.\"editDevice\", rights.\"deleteDevice\","
                             "rights.\"alertsView\", rights.\"alertsDelete\", rights.\"generalSettingsView\", rights.\"generalSettingsChange\","
                             "rights.\"videosView\", rights.\"videosDecrypt\", rights.\"videosDelete\" FROM users INNER JOIN rights ON rights.\"rightId\" = users.rights"
                             " WHERE username = '"+username+"';";
    MainQuery->prepare(SQLQuery);
    if(!MainQuery->exec())
    {
        qDebug() << "Unable to get role atributes. SQL Error: "<< MainQuery->lastError() << "Current query: " << MainQuery->lastQuery();
        return;
    }
    MainQuery->first();
    for (int i=0;i<list.size();i++) {
        if(MainQuery->value(i+1).toBool())
        {
            ui->RoleAtributes_listWidget->addItem(list.value(i));
        }
        RALCounter++;
    }

}

bool Users::CheckForRoot()
{
    //Проверка на рут
    QSqlQuery check_query;
    if(!check_query.exec("SELECT \"accessLevel\" FROM \"vUsers\" WHERE username = '"+username+"';"))
    {
        qDebug() << "Unable to check root status. SQL Error: " << check_query.lastError() << check_query.lastQuery();
    }
    check_query.first();
    if(check_query.value(0).toInt()==0)
    {
        return true;
    }
    else
    {
        QMessageBox::critical(this, "Ошибка доступа", "У вас недостаточно прав для доступа к этому разделу");
        return false;
    }
}




void Users::on_MandatoryMarksEditor_toolButton_clicked()
{

    if(CheckForRoot())
    {
        MandatoryMarksEditor *MacEditor = new MandatoryMarksEditor(this, username);
        MacEditor->setModal(true);
        MacEditor->exec();
        delete MacEditor;

    }

}





void Users::on_MandatoryGroupsEditor_toolButton_clicked()
{
    //Открыть редактор мандатных групп
    MandatoryGroups *rights = new MandatoryGroups(this, username);
    rights->setModal(true);
    rights->exec();
    delete rights;
}




void Users::on_ChangePassword_action_triggered()
{
    qDebug() << "dssdsdsds";
}
