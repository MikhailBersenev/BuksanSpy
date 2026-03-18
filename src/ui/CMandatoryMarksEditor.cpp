#include "CMandatoryMarksEditor.h"
#include "ui_CMandatoryMarksEditor.h"
#include "CMandatoryMarkCreator.h"
#include <QtSql>
#include <QMessageBox>
#include "security/CAccessManager.h"
#include "Loggerd.h"
#include <QString>

CMandatoryMarksEditor::CMandatoryMarksEditor(QWidget *parent, QString strUser) :
    QDialog(parent),
    m_pUi(new Ui::CMandatoryMarksEditor)
{
    m_pUi->setupUi(this);
    m_strUsername = strUser;
    fUpdateModels();
    LOG_INFO_MSG((QStringLiteral("CMandatoryMarksEditor dialog user=") + strUser).toStdString());
}

CMandatoryMarksEditor::~CMandatoryMarksEditor()
{
    delete m_pUi;
}

void CMandatoryMarksEditor::fUpdateModels()
{
    m_mandatoryMarksModel.setQuery("SELECT * FROM \"mandatoryMarks\" WHERE \"accessLevel\" >0 ORDER BY \"accessLevel\" ASC;");
    m_pUi->MandatoryMarks_listView->setModel(&m_mandatoryMarksModel);
    m_pUi->MandatoryMarks_listView->setModelColumn(1);
}

void CMandatoryMarksEditor::on_addMandatoryMark_pushButton_clicked()
{
    CMandatoryMarkCreator *l_pCreator = new CMandatoryMarkCreator(this);
    l_pCreator->setModal(true);
    l_pCreator->exec();
    delete l_pCreator;
    fUpdateModels();
}

void CMandatoryMarksEditor::on_DeleteMandatoryMark_pushButton_clicked()
{ //Удаление мандатной метки
    QSqlQuery l_deleteMandatoryMark;
    const int l_nCurrentId = m_mandatoryMarksModel.data(m_mandatoryMarksModel.index(m_pUi->MandatoryMarks_listView->currentIndex().row(),0)).toInt();
    const QString l_strCurrentDescription = m_mandatoryMarksModel.data(m_mandatoryMarksModel.index(m_pUi->MandatoryMarks_listView->currentIndex().row(),1)).toString();
    if(!l_deleteMandatoryMark.exec("SELECT * FROM rights WHERE \"mandatoryMark\" = "+QString::number(l_nCurrentId)+";"))
    {
        LOG_CRITICAL_MSG((QStringLiteral("Unable to check mandatory groups: ") + l_deleteMandatoryMark.lastError().text() + QLatin1Char(' ') + l_deleteMandatoryMark.lastQuery()).toStdString());
        return;
    }
    l_deleteMandatoryMark.first();
    if(l_deleteMandatoryMark.size()>0)
    {
        QMessageBox::critical(this, "Error", "Mandate label is currently assigned to " +QString::number(l_deleteMandatoryMark.size())+" groups. \n Change their labels before deletion.");
        return;
    }
    else
    {
        if(!l_deleteMandatoryMark.exec("DELETE FROM \"mandatoryMarks\" WHERE \"mandatoryMarkId\" = "+QString::number(l_nCurrentId)+";"))
        {
            LOG_CRITICAL_MSG((QStringLiteral("Unable to delete mandatory mark: ") + l_deleteMandatoryMark.lastError().text() + QLatin1Char(' ') + l_deleteMandatoryMark.lastQuery()).toStdString());
            return;
        }
        else
        {
            QMessageBox::information(this, "Mandate label removal", "Mandate label \""+l_strCurrentDescription+"\" was successfully removed");
            fUpdateModels();
        }
    }
}

