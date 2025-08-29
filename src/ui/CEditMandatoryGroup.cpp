#include "CEditMandatoryGroup.h"
#include "ui_CEditMandatoryGroup.h"
#include <QDebug>
#include <QtWidgets>
#include <QMessageBox>

CEditMandatoryGroup::CEditMandatoryGroup(QWidget *parent, int nMode, int nMandatoryGroupId, QString strMandatoryGroupDescription) :
    QDialog(parent),
    m_pUi(new Ui::CEditMandatoryGroup),
    m_nMode(nMode)
{
    m_pUi->setupUi(this);
    //Конструктор
    m_mandatoryGroupsModel.setQuery("SELECT \"mandatoryMarkId\", description FROM \"mandatoryMarks\" WHERE \"accessLevel\" > 0");
    m_pUi->MandatoryMark_comboBox->setModel(&m_mandatoryGroupsModel);
    m_pUi->MandatoryMark_comboBox->setModelColumn(1);
    m_pMainQuery = new QSqlQuery;
    switch (nMode) {
    case 0:
        m_pMainQuery->prepare("INSERT INTO rights (description, \"usersControl\", \"addDevice\", \"editDevice\", \"deleteDevice\", "
                           "\"alertsView\", \"alertsDelete\", \"generalSettingsView\", \"generalSettingsChange\", \"videosView\", \"videosDecrypt\", \"videosDelete\", \"mandatoryMark\")"
                           "VALUES (:description, :userscontrol, :adddev, :editdev, :deldev, :alertsview, :alertsdel, :gsview, :gschange, :videosview, :videosdecrypt, :videosdel, :mark);");
        fSetDefaultValues();
        break;
    case 1:
        m_pMainQuery->prepare("UPDATE rights SET description = :description, \"usersControl\" = :userscontrol, \"addDevice\" = :adddev, \"editDevice\" = :editdev, \"deleteDevice\" = :deldev, \"alertsView\" = :alertsview,"
                           "\"alertsDelete\" = :alertsdel, \"generalSettingsView\" = :gsview, \"generalSettingsChange\" = :gschange, \"videosView\" = :videosview, \"videosDecrypt\" = :videosdecrypt, \"videosDelete\" = :videosdel, \"mandatoryMark\" = :mark WHERE \"rightId\" = "+QString::number(nMandatoryGroupId)+";");
        fSetDefaultValues();
        fRightsParser(nMandatoryGroupId);
        m_pUi->GroupName_Edit->setText(strMandatoryGroupDescription);
        break;
    }
}

CEditMandatoryGroup::~CEditMandatoryGroup()
{
    delete m_pUi;
}

void CEditMandatoryGroup::on_buttonBox_rejected()
{
    delete m_pMainQuery;
    close(); //удаляем объект запроса и закрываем форму
}

void CEditMandatoryGroup::on_UserControl_checkBox_stateChanged(int nArg1)
{
    Q_UNUSED(nArg1)
    if(!m_pUi->UserControl_checkBox->isChecked())
    {
        m_pMainQuery->bindValue(":userscontrol", false);
    }
    else {
        m_pMainQuery->bindValue(":userscontrol", true);
    }
}

void CEditMandatoryGroup::on_AddDevice_checkBox_stateChanged(int nArg1)
{
    Q_UNUSED(nArg1)
    if(!m_pUi->AddDevice_checkBox->isChecked())
    {
        m_pMainQuery->bindValue(":adddev", false);
    }
    else
    {
        m_pMainQuery->bindValue(":adddev", true);
    }
}

void CEditMandatoryGroup::on_editDevice_checkBox_stateChanged(int nArg1)
{
    Q_UNUSED(nArg1)
    if(!m_pUi->editDevice_checkBox->isChecked())
    {
        m_pMainQuery->bindValue(":editdev", false);
    }
    else
    {
        m_pMainQuery->bindValue(":editdev", true);
    }
}

void CEditMandatoryGroup::on_DeleteDevice_checkBox_stateChanged(int nArg1)
{
    Q_UNUSED(nArg1)
    if(!m_pUi->DeleteDevice_checkBox->isChecked())
    {
        m_pMainQuery->bindValue(":deldev", false);
    }
    else
    {
        m_pMainQuery->bindValue(":deldev", true);
    }
}

void CEditMandatoryGroup::on_alertsView_checkBox_stateChanged(int nArg1)
{
    Q_UNUSED(nArg1)
    if(!m_pUi->alertsView_checkBox->isChecked())
    {
        m_pMainQuery->bindValue(":alertsview", false);
    }
    else
    {
        m_pMainQuery->bindValue(":alertsview", true);
    }
}

void CEditMandatoryGroup::on_alertsDelete_checkBox_stateChanged(int nArg1)
{
    Q_UNUSED(nArg1)
    if(!m_pUi->alertsDelete_checkBox->isChecked())
    {
        m_pMainQuery->bindValue(":alertsdel", false);
    }
    else
    {
        m_pMainQuery->bindValue(":alertsdel", true);
    }
}

void CEditMandatoryGroup::on_generalSettingsView_checkBox_stateChanged(int nArg1)
{
    Q_UNUSED(nArg1)
    if(!m_pUi->generalSettingsView_checkBox->isChecked())
    {
        m_pMainQuery->bindValue(":gsview", false);
    }
    else
    {
        m_pMainQuery->bindValue(":gsview", true);
    }
}

void CEditMandatoryGroup::on_generalSettingsChange_checkBox_stateChanged(int nArg1)
{
    Q_UNUSED(nArg1)
    if(!m_pUi->generalSettingsChange_checkBox->isChecked())
    {
        m_pMainQuery->bindValue(":gschange", false);
    }
    else
    {
        m_pMainQuery->bindValue(":gschange", true);
    }
}

void CEditMandatoryGroup::on_VideosView_checkBox_stateChanged(int nArg1)
{
    Q_UNUSED(nArg1)
    if(!m_pUi->VideosView_checkBox->isChecked())
    {
        m_pMainQuery->bindValue(":videosview", false);
    }
    else
    {
        m_pMainQuery->bindValue(":videosview", true);
    }
}

void CEditMandatoryGroup::on_VideosDecrypt_checkBox_stateChanged(int nArg1)
{
    Q_UNUSED(nArg1)
    if(!m_pUi->VideosDecrypt_checkBox->isChecked())
    {
        m_pMainQuery->bindValue(":videosdecrypt", false);
    }
    else
    {
        m_pMainQuery->bindValue(":videosdecrypt", true);
    }
}

void CEditMandatoryGroup::on_videosDelete_checkBox_stateChanged(int nArg1)
{
    Q_UNUSED(nArg1)
    if(!m_pUi->videosDelete_checkBox->isChecked())
    {
        m_pMainQuery->bindValue(":videosdel", false);
    }
    else
    {
        m_pMainQuery->bindValue(":videosdel", true);
    }
}

void CEditMandatoryGroup::on_buttonBox_accepted()
{
    int l_nCurrentIndex = m_mandatoryGroupsModel.data(m_mandatoryGroupsModel.index(m_pUi->MandatoryMark_comboBox->currentIndex(),0)).toInt();
    m_pMainQuery->bindValue(":mark", l_nCurrentIndex);
    m_pMainQuery->bindValue(":description", m_pUi->GroupName_Edit->text());
    if(!m_pMainQuery->exec())
    {
        qDebug() << "Unable to save rights" << m_pMainQuery->lastError() << m_pMainQuery->lastQuery();
        return;
    }
    else
    {
        if(m_nMode == 0)
        {
            QMessageBox::information(this, "Создание мандатной группы", "Группа создана");
        }
        else
        {
            QMessageBox::information(this, "Редактирование мандатной группы", "Настройки сохранены");
        }
        close();
    }
    if(m_pUi->GroupName_Edit->text().isEmpty())
    {
        QMessageBox::warning(this, "Внимание!", "Укажите название мандатной группы");
    }
}

void CEditMandatoryGroup::fSetDefaultValues()
{
    m_pMainQuery->bindValue(":userscontrol", false);
    m_pMainQuery->bindValue(":adddev", false);
    m_pMainQuery->bindValue(":editdev", false);
    m_pMainQuery->bindValue(":deldev", false);
    m_pMainQuery->bindValue(":alertsview", false);
    m_pUi->alertsDelete_checkBox->setChecked(false);
    m_pMainQuery->bindValue(":alertsdel", false);
    m_pMainQuery->bindValue(":gsview", false);
    m_pMainQuery->bindValue(":gschange", false);
    m_pMainQuery->bindValue(":videosview", false);
    m_pMainQuery->bindValue(":videosdecrypt", false);
    m_pMainQuery->bindValue(":videosdel", false);
}

void CEditMandatoryGroup::fRightsParser(int nMandatoryGroupId)
{
    QSqlQuery l_rightsQuery;
    l_rightsQuery.prepare("SELECT \"usersControl\", \"addDevice\", \"editDevice\", \"deleteDevice\", \"alertsView\", \"alertsDelete\", \"generalSettingsView\", \"generalSettingsChange\", \"videosView\", \"videosDecrypt\", \"videosDelete\" FROM rights WHERE \"rightId\" = :rightid;");
    l_rightsQuery.bindValue(":rightid", nMandatoryGroupId);
    if(!l_rightsQuery.exec())
    {
        qDebug() << "Unable to get rights" << l_rightsQuery.lastError() << l_rightsQuery.lastQuery();
        return;
    }
    l_rightsQuery.first();
    if(l_rightsQuery.value(0).toBool())
    {
        m_pUi->UserControl_checkBox->setChecked(true);
        m_pMainQuery->bindValue(":userscontrol", true);
    }
    if(l_rightsQuery.value(1).toBool())
    {
        m_pUi->AddDevice_checkBox->setChecked(true);
        m_pMainQuery->bindValue(":adddev", true);
    }
    if(l_rightsQuery.value(2).toBool())
    {
        m_pUi->editDevice_checkBox->setChecked(true);
        m_pMainQuery->bindValue(":editdev", true);
    }
    if(l_rightsQuery.value(3).toBool())
    {
        m_pUi->DeleteDevice_checkBox->setChecked(true);
        m_pMainQuery->bindValue(":deldev", true);
    }
    if(l_rightsQuery.value(4).toBool())
    {
        m_pUi->alertsView_checkBox->setChecked(true);
        m_pMainQuery->bindValue(":alertsview", true);
    }
    if(l_rightsQuery.value(5).toBool())
    {
        m_pUi->alertsDelete_checkBox->setChecked(true);
        m_pMainQuery->bindValue(":alertsdel", true);
    }
    if(l_rightsQuery.value(6).toBool())
    {
        m_pUi->generalSettingsView_checkBox->setChecked(true);
        m_pMainQuery->bindValue(":gsview", true);
    }
    if(l_rightsQuery.value(7).toBool())
    {
        m_pUi->generalSettingsChange_checkBox->setChecked(true);
        m_pMainQuery->bindValue(":gschange", true);
    }
    if(l_rightsQuery.value(8).toBool())
    {
        m_pUi->VideosView_checkBox->setChecked(true);
        m_pMainQuery->bindValue(":videosview", true);
    }
    if(l_rightsQuery.value(9).toBool())
    {
        m_pUi->VideosDecrypt_checkBox->setChecked(true);
        m_pMainQuery->bindValue(":videosdecrypt", true);
    }
    if(l_rightsQuery.value(10).toBool())
    {
        m_pUi->videosDelete_checkBox->setChecked(true);
        m_pMainQuery->bindValue(":videosdel", true);
    }
}


