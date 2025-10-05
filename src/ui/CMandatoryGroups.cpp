#include "CMandatoryGroups.h"
#include "CEditMandatoryGroup.h"
#include "ui_CMandatoryGroups.h"
#include <QtWidgets>
#include <QMessageBox>
#include <QDebug>

CMandatoryGroups::CMandatoryGroups(QWidget *parent, QString strUser) :
    QDialog(parent),
    m_pUi(new Ui::CMandatoryGroups)
{
    m_pUi->setupUi(this);
    m_strUsername = strUser;
    fUpdateModels();
}

CMandatoryGroups::~CMandatoryGroups()
{
    delete m_pUi;
}

void CMandatoryGroups::on_DeleteMandatoryGroup_Button_clicked()
{
    m_pAccessManager = new CAccessManager(this);
    QMessageBox::StandardButton l_reply;
    QString l_strCurrentDesc = m_mandatoryGroupsModel.data(m_mandatoryGroupsModel.index(m_pUi->MandatoryGroupslistView->currentIndex().row(),1)).toString();
    l_reply = QMessageBox::question(this, "Mandate group removal", "Are you sure you want to remove this mandate group? \n WARNING! Removal of the mandate group will cause removal its members"
                                                                     " and ALL their information", QMessageBox::Yes|QMessageBox::No);
    if(l_reply==QMessageBox::No or l_strCurrentDesc == m_pAccessManager->fGetMandatoryGroup(m_strUsername))
    {
        return;
    }
    else
    {
        m_pMainQuery = new QSqlQuery;
        m_pMainQuery->prepare("DELETE FROM rights WHERE description = :current;");
        m_pMainQuery->bindValue(":current", l_strCurrentDesc);
        if(!m_pMainQuery->exec())
        {
            qDebug() << "Unable to delete group" << m_pMainQuery->lastError() << m_pMainQuery->lastQuery();
            return;
        }
        else
        {
            QMessageBox::information(this, "Mandate groups", "Mandate group  deleted successfully");
            fUpdateModels();
        }
    }
}

void CMandatoryGroups::on_AddMandatoryGroup_Button_clicked()
{
    //показываем форму редактирования группы в режиме добавления
    m_pWindow = new CEditMandatoryGroup(this, 0);
    m_pWindow->setWindowTitle("Mandate group creation");
    m_pWindow->setModal(true);
    m_pWindow->exec();
    delete m_pWindow;
}

void CMandatoryGroups::fUpdateModels()
{
    m_mandatoryGroupsModel.setQuery("SELECT rights.\"rightId\", rights.description, rights.\"usersControl\", rights.\"addDevice\", rights.\"editDevice\", rights.\"deleteDevice\","
                                   "rights.\"alertsView\", rights.\"alertsDelete\", rights.\"generalSettingsView\", rights.\"generalSettingsChange\", rights.\"videosView\","
                                   "rights.\"videosDecrypt\", rights.\"videosDelete\", \"mandatoryMarks\".description  \"mandatoryMark\" FROM rights INNER JOIN \"mandatoryMarks\" ON \"mandatoryMarks\".\"mandatoryMarkId\"=rights.\"mandatoryMark\""
                                   "WHERE \"mandatoryMarks\".\"accessLevel\" >-1 ;");
    m_pUi->MandatoryGroupslistView->setModel(&m_mandatoryGroupsModel);
    m_pUi->MandatoryGroupslistView->setModelColumn(1);
}

void CMandatoryGroups::on_MandatoryGroupslistView_clicked(const QModelIndex &index)
{
    m_pUi->MandatoryMark_label->setText(m_mandatoryGroupsModel.data(m_mandatoryGroupsModel.index(index.row(),13)).toString());
    QStringList l_list;
    l_list << "Users and groups setup" << "Add devices" << "Edit devices" << "Remove devices" << "View event journal " << "Clear event  journal" << "View general settings" << "Change general settings" << "View media journal" << "Export media" << "Delete media";
    if(m_nRALCounter!=0)
    {
        m_pUi->RoleAtributes_listWidget->clear();
        m_nRALCounter =0;
    }
    for (int l_i=0;l_i<l_list.size();l_i++) {
        if(m_mandatoryGroupsModel.query().value(l_i+2).toBool())
        {
            m_pUi->RoleAtributes_listWidget->addItem(l_list.value(l_i));
        }
        m_nRALCounter++;
    }
}

void CMandatoryGroups::on_EditMandatoryGroup_pushButton_clicked()
{
    //показываем форму редактирования группы в режиме редактирования
    const int l_nMandatoryGroupId  = m_mandatoryGroupsModel.data(m_mandatoryGroupsModel.index(m_pUi->MandatoryGroupslistView->currentIndex().row(),0)).toInt();
    const QString l_strMandatoryGroupDescription = m_mandatoryGroupsModel.data(m_mandatoryGroupsModel.index(m_pUi->MandatoryGroupslistView->currentIndex().row(),1)).toString();
    m_pWindow = new CEditMandatoryGroup(this, 1, l_nMandatoryGroupId, l_strMandatoryGroupDescription);
    m_pWindow->setWindowTitle("Edit mandate group "+l_strMandatoryGroupDescription);
    m_pWindow->setModal(true);
    m_pWindow->exec();
    delete m_pWindow;
    fUpdateModels();
}
