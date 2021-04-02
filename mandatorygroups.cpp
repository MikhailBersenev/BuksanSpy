#include "mandatorygroups.h"
#include "editmandatorygroup.h"
#include "ui_mandatorygroups.h"
#include <QtWidgets>
MandatoryGroups::MandatoryGroups(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MandatoryGroups)
{
    ui->setupUi(this);
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
    QString CurrentDesc = MandatoryGroups_model.data(MandatoryGroups_model.index(ui->MandatoryGroups_Table->currentIndex().row(),0)).toString();
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
    //показываем форму редактирования группы
    Window = new EditMandatoryGroup(this);
    Window->mode = 0;
    Window->setWindowTitle("Добавление мандатной группы");
    Window->setModal(true);
    Window->exec();
    delete Window;
}

void MandatoryGroups::UpdateModels()
{
    MandatoryGroups_model.setQuery("SELECT rights.description, rights.\"usersControl\", rights.\"addDevice\", rights.\"editDevice\", rights.\"deleteDevice\",  "
                                   "rights.\"alertsView\", rights.\"alertsDelete\", rights.\"generalSettingsView\", rights.\"generalSettingsChange\","
                                   "rights.\"videosView\", rights.\"videosDecrypt\", rights.\"videosDelete\" "
                                   "FROM rights;");
    ui->MandatoryGroups_Table->setModel(&MandatoryGroups_model);

}
