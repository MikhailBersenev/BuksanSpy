#include "mandatorygroups.h"
#include "editmandatorygroup.h"
#include "ui_mandatorygroups.h"
#include <QtWidgets>
MandatoryGroups::MandatoryGroups(QWidget *parent, QString user) :
    QDialog(parent),
    ui(new Ui::MandatoryGroups)
{
    ui->setupUi(this);
    username = user;
    UpdateModels();  


}

MandatoryGroups::~MandatoryGroups()
{
    delete ui;
}

void MandatoryGroups::on_DeleteMandatoryGroup_Button_clicked()
{
    AccessManager_var = new AccessManager(this);
    QMessageBox::StandardButton reply;
    QString CurrentDesc = MandatoryGroups_model.data(MandatoryGroups_model.index(ui->MandatoryGroupslistView->currentIndex().row(),1)).toString();
    reply = QMessageBox::question(this, "Удаление мандатной группы", "Вы уверены, что хотите удалить группу? \n ВНИМАНИЕ! Удаление мандатной группы приведет к удалению всех ее членов"
                                                                     " и всей связанной с ними информации", QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::No or CurrentDesc == AccessManager_var->GetMandatoryGroup(username))
    {
        return;
    }
    else
    {
        MainQuery = new QSqlQuery;
        MainQuery->prepare("DELETE FROM rights WHERE description = :current;");
        MainQuery->bindValue(":current", CurrentDesc);
        if(!MainQuery->exec())
        {
            qDebug() << "Unable to delete group" << MainQuery->lastError() << MainQuery->lastQuery();
            return;
        }
        else
        {
            QMessageBox::information(this, "Мандатные группы", "Мандатная группа удалена");
            UpdateModels();

        }
    }
}

void MandatoryGroups::on_AddMandatoryGroup_Button_clicked()
{
    //показываем форму редактирования группы в режиме добавления
    Window = new EditMandatoryGroup(this, 0);
    Window->setWindowTitle("Добавление мандатной группы");
    Window->setModal(true);
    Window->exec();
    delete Window;
}

void MandatoryGroups::UpdateModels()
{
    MandatoryGroups_model.setQuery("SELECT rights.\"rightId\", rights.description, rights.\"usersControl\", rights.\"addDevice\", rights.\"editDevice\", rights.\"deleteDevice\","
                                   "rights.\"alertsView\", rights.\"alertsDelete\", rights.\"generalSettingsView\", rights.\"generalSettingsChange\", rights.\"videosView\","
                                   "rights.\"videosDecrypt\", rights.\"videosDelete\", \"mandatoryMarks\".description  \"mandatoryMark\" FROM rights INNER JOIN \"mandatoryMarks\" ON \"mandatoryMarks\".\"mandatoryMarkId\"=rights.\"mandatoryMark\""
                                   "WHERE \"mandatoryMarks\".\"accessLevel\" >-1 ;");
    ui->MandatoryGroupslistView->setModel(&MandatoryGroups_model);
    ui->MandatoryGroupslistView->setModelColumn(1);
}

void MandatoryGroups::on_MandatoryGroupslistView_clicked(const QModelIndex &index)
{
    ui->MandatoryMark_label->setText(MandatoryGroups_model.data(MandatoryGroups_model.index(index.row(),13)).toString());
    QStringList list;
    list << "Управление пользователями и группами" << "Добавление устройств" << "Редактирование устройств" << "Удаление устройств" << "Просмотр журнала событий" << "Очистка журнала событий" << "Просмотр настроек ПС" << "Изменение настроек ПС" << "Просмотр журнала видеозаписей" << "Выгрузка видеозаписей в файл" << "Удаление видеозаписей";
    if(RALCounter!=0)
    {
        ui->RoleAtributes_listWidget->clear();
        RALCounter =0;
    }
    for (int i=0;i<list.size();i++) {
        if(MandatoryGroups_model.query().value(i+2).toBool())
        {
            ui->RoleAtributes_listWidget->addItem(list.value(i));
        }
        RALCounter++;
    }



}

void MandatoryGroups::on_EditMandatoryGroup_pushButton_clicked()
{
    //показываем форму редактирования группы в режиме редактирования
    const int MandatoryGroupId  = MandatoryGroups_model.data(MandatoryGroups_model.index(ui->MandatoryGroupslistView->currentIndex().row(),0)).toInt();
    const QString MandatoryGroupDescription = MandatoryGroups_model.data(MandatoryGroups_model.index(ui->MandatoryGroupslistView->currentIndex().row(),1)).toString();
    Window = new EditMandatoryGroup(this, 1, MandatoryGroupId, MandatoryGroupDescription);
    Window->setWindowTitle("Редактирование мандатной группы "+MandatoryGroupDescription);
    Window->setModal(true);
    Window->exec();
    delete Window;
}
