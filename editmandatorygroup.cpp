#include "editmandatorygroup.h"
#include "ui_editmandatorygroup.h"
#include <QDebug>
#include <QtWidgets>
EditMandatoryGroup::EditMandatoryGroup(QWidget *parent, int mode, int MandatoryGroupId, QString MandatoryGroupDescription) :
    QDialog(parent),
    ui(new Ui::EditMandatoryGroup)
{
    ui->setupUi(this);
    //Конструктор
    MandatoryGroups_model.setQuery("SELECT \"mandatoryMarkId\", description FROM \"mandatoryMarks\" WHERE \"accessLevel\" > 0");
    ui->MandatoryMark_comboBox->setModel(&MandatoryGroups_model);
    ui->MandatoryMark_comboBox->setModelColumn(1);
    MainQuery = new QSqlQuery;
    SetDefaultValues();
    switch (mode) {
    case 0:
        MainQuery->prepare("INSERT INTO rights (description, \"usersControl\", \"addDevice\", \"editDevice\", \"deleteDevice\", "
                           "\"alertsView\", \"alertsDelete\", \"generalSettingsView\", \"generalSettingsChange\", \"videosView\", \"videosDecrypt\", \"videosDelete\", \"mandatoryMark\")"
                           "VALUES (:description, :userscontrol, :adddev, :editdev, :deldev, :alertsview, :alertsdel, :gsview, :gschange, :videosview, :videosdecrypt, :videosdel, :mark);");
        break;
    case 1:
        MainQuery->prepare("UPDATE rights SET description = :description, \"usersControl\" = :userscontrol, \"addDevice\" = :adddev, \"editDevice\" = :editdev, \"deleteDevice\" = :deldev, \"alertsView\" = :alertsview,"
                           "\"alertsDelete\" = :alertsdel, \"generalSettingsView\" = :gsview, \"generalSettingsChange\" = :gschange, \"videosView\" = :videosview, \"videosDecrypt\" = :videosdecrypt, \"videosDelete\" = :videosdel, \"mandatoryMark\" = :mark WHERE \"rightId\" = "+QString::number(MandatoryGroupId)+";");
        rightsParser(MandatoryGroupId);
        ui->GroupName_Edit->setText(MandatoryGroupDescription);
        break;


    }
}

EditMandatoryGroup::~EditMandatoryGroup()
{
    delete ui;
}

void EditMandatoryGroup::on_buttonBox_rejected()
{
    delete MainQuery;
    close(); //удаляем объект запроса и закрываем форму
}

void EditMandatoryGroup::on_UserControl_checkBox_stateChanged(int arg1)
{
    Q_UNUSED(arg1)
    if(!ui->UserControl_checkBox->isChecked())
    {
        MainQuery->bindValue(":userscontrol", false);
    }
    else {
        MainQuery->bindValue(":userscontrol", true);
    }

}




void EditMandatoryGroup::on_AddDevice_checkBox_stateChanged(int arg1)
{
    Q_UNUSED(arg1)
    if(!ui->AddDevice_checkBox->isChecked())
    {
        MainQuery->bindValue(":adddev", false);
    }
    else
    {
        MainQuery->bindValue(":adddev", true);
    }
}

void EditMandatoryGroup::on_editDevice_checkBox_stateChanged(int arg1)
{
    Q_UNUSED(arg1)
    if(!ui->editDevice_checkBox->isChecked())
    {
        MainQuery->bindValue(":editdev", false);
    }
    else
    {
        MainQuery->bindValue(":editdev", true);
    }
}

void EditMandatoryGroup::on_DeleteDevice_checkBox_stateChanged(int arg1)
{
    Q_UNUSED(arg1)
    if(!ui->DeleteDevice_checkBox->isChecked())
    {
        MainQuery->bindValue(":deldev", false);
    }
    else
    {
        MainQuery->bindValue(":deldev", true);
    }
}

void EditMandatoryGroup::on_alertsView_checkBox_stateChanged(int arg1)
{
    Q_UNUSED(arg1)
    if(!ui->alertsView_checkBox->isChecked())
    {
        MainQuery->bindValue(":alertsview", false);
        ui->alertsDelete_checkBox->setChecked(false);
        ui->alertsDelete_checkBox->setEnabled(false);
    }
    else
    {
        MainQuery->bindValue(":alertsview", true);
        ui->alertsDelete_checkBox->setEnabled(true);
    }
}

void EditMandatoryGroup::on_alertsDelete_checkBox_stateChanged(int arg1)
{
    Q_UNUSED(arg1)
    if(!ui->alertsDelete_checkBox->isChecked())
    {
        MainQuery->bindValue(":alertsdel", false);
    }
    else
    {
        MainQuery->bindValue(":alertsdel", true);
    }
}

void EditMandatoryGroup::on_generalSettingsView_checkBox_stateChanged(int arg1)
{
    Q_UNUSED(arg1)
    if(!ui->generalSettingsView_checkBox->isChecked())
    {
        MainQuery->bindValue(":gsview", false);
        ui->generalSettingsChange_checkBox->setChecked(false);
        ui->generalSettingsChange_checkBox->setEnabled(false);
    }
    else
    {
        MainQuery->bindValue(":gsview", true);
        ui->generalSettingsChange_checkBox->setEnabled(true);
    }
}

void EditMandatoryGroup::on_generalSettingsChange_checkBox_stateChanged(int arg1)
{
    Q_UNUSED(arg1)
    if(!ui->generalSettingsChange_checkBox->isChecked())
    {
        MainQuery->bindValue(":gschange", false);
    }
    else
    {
        MainQuery->bindValue(":gschange", true);
    }
}

void EditMandatoryGroup::on_VideosView_checkBox_stateChanged(int arg1)
{
    Q_UNUSED(arg1)
    if(!ui->VideosView_checkBox->isChecked())
    {
        MainQuery->bindValue(":videosview", false);
        ui->VideosDecrypt_checkBox->setChecked(false);
        ui->videosDelete_checkBox->setChecked(false);
        ui->videosDelete_checkBox->setEnabled(false);
        ui->VideosDecrypt_checkBox->setEnabled(false);
    }
    else
    {
        MainQuery->bindValue(":videosview", true);
        ui->VideosDecrypt_checkBox->setEnabled(true);
        ui->videosDelete_checkBox->setEnabled(true);

    }
}

void EditMandatoryGroup::on_VideosDecrypt_checkBox_stateChanged(int arg1)
{
    Q_UNUSED(arg1)
    if(!ui->VideosDecrypt_checkBox->isChecked())
    {
        MainQuery->bindValue(":videosdecrypt", false);
    }
    else
    {
        MainQuery->bindValue(":videosdecrypt", true);
    }
}

void EditMandatoryGroup::on_videosDelete_checkBox_stateChanged(int arg1)
{
    Q_UNUSED(arg1)
    if(!ui->generalSettingsChange_checkBox->isChecked())
    {
        MainQuery->bindValue(":videosdel", false);
    }
    else
    {
        MainQuery->bindValue(":videosdel", true);
    }
}

void EditMandatoryGroup::on_buttonBox_accepted()
{
    int CurrentIndex = MandatoryGroups_model.data(MandatoryGroups_model.index(ui->MandatoryMark_comboBox->currentIndex(),0)).toInt();
    MainQuery->bindValue(":mark", CurrentIndex);
    if(!ui->GroupName_Edit->text().isEmpty())
    {
        MainQuery->bindValue(":description", ui->GroupName_Edit->text());
        if(!MainQuery->exec())
        {
            qDebug() << "Unable to save settings" << MainQuery->lastError() << MainQuery->lastQuery();
            return;
        }
        else
        {
            QMessageBox::information(this, "Редактирование мандатной группы", "Настройки сохранены");
            close();
        }
    }
    else
    {
        QMessageBox::warning(this, "Внимание!", "Укажите название мандатной группы");
    }
}

void EditMandatoryGroup::SetDefaultValues()
{
    MainQuery->bindValue(":userscontrol", false);
    MainQuery->bindValue(":adddev", false);
    MainQuery->bindValue(":alertsdel", false);
    MainQuery->bindValue(":alertsview", false);
    ui->alertsDelete_checkBox->setChecked(false);
    ui->alertsDelete_checkBox->setEnabled(false);
    MainQuery->bindValue(":deldev", false);
    MainQuery->bindValue(":editdev", false);
    MainQuery->bindValue(":gschange", false);
    MainQuery->bindValue(":gsview", false);
    ui->generalSettingsChange_checkBox->setChecked(false);
    ui->generalSettingsChange_checkBox->setEnabled(false);
    MainQuery->bindValue(":userscontrol", false);
    MainQuery->bindValue(":videosdecrypt", false);
    MainQuery->bindValue(":videosdel", false);
    MainQuery->bindValue(":videosview", false);
    ui->VideosDecrypt_checkBox->setChecked(false);
    ui->videosDelete_checkBox->setChecked(false);
    ui->videosDelete_checkBox->setEnabled(false);
    ui->VideosDecrypt_checkBox->setEnabled(false);
}

void EditMandatoryGroup::rightsParser(int MandatoryGroupId)
{ //Парсер ролевых атрибутов мандатной группы
    QSqlQuery Rights_query;
    if(!Rights_query.exec("SELECT * FROM rights WHERE \"rightId\" = "+QString::number(MandatoryGroupId)+";"))
    {
        qDebug() << "Unable to check role rights. SQL Error: " << Rights_query.lastError() << Rights_query.lastQuery();
    }
    while (Rights_query.next()) {
        if(Rights_query.value(2).toBool())
        {
            ui->UserControl_checkBox->setChecked(true);
            MainQuery->bindValue(":userscontrol", true);
        }
        if(Rights_query.value(3).toBool())
        {
            ui->AddDevice_checkBox->setChecked(true);
            MainQuery->bindValue(":adddev", true);
        }
        if(Rights_query.value(4).toBool())
        {
            ui->DeleteDevice_checkBox->setChecked(true);
            MainQuery->bindValue(":deldev", true);
        }
        if(Rights_query.value(5).toBool())
        {
            ui->alertsView_checkBox->setChecked(true);
            MainQuery->bindValue(":alertsview", true);
        }
        if(Rights_query.value(6).toBool())
        {
            ui->alertsDelete_checkBox->setChecked(true);
            MainQuery->bindValue(":alertsdel", true);
        }
        if(Rights_query.value(7).toBool())
        {
            ui->generalSettingsView_checkBox->setChecked(true);
            MainQuery->bindValue(":gsview", true);
        }
        if(Rights_query.value(8).toBool())
        {
            ui->generalSettingsChange_checkBox->setChecked(true);
            MainQuery->bindValue(":gschange", true);
        }
        if(Rights_query.value(9).toBool())
        {
            ui->VideosView_checkBox->setChecked(true);
            MainQuery->bindValue(":videosview", true);
        }
        if(Rights_query.value(10).toBool())
        {
            ui->VideosDecrypt_checkBox->setChecked(true);
            MainQuery->bindValue(":videosdecrypt", true);
        }
        if(Rights_query.value(11).toBool())
        {
            ui->videosDelete_checkBox->setChecked(true);
            MainQuery->bindValue(":videosdel", true);
        }





    }
}


