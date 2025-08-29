#include "CMandatoryMarksEditor.h"
#include "ui_CMandatoryMarksEditor.h"
#include "CMandatoryMarkCreator.h"
#include <QtSql>
#include <QMessageBox>
#include "security/CAccessManager.h"
#include <QDebug>

CMandatoryMarksEditor::CMandatoryMarksEditor(QWidget *parent, QString strUser) :
    QDialog(parent),
    m_pUi(new Ui::CMandatoryMarksEditor)
{
    m_pUi->setupUi(this);
    m_strUsername = strUser;
    fUpdateModels();
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
        qDebug() << "Unable to check mandatory groups. SQL Error: " << l_deleteMandatoryMark.lastError() << l_deleteMandatoryMark.lastQuery();
        return;
    }
    l_deleteMandatoryMark.first();
    if(l_deleteMandatoryMark.size()>0)
    {
        QMessageBox::critical(this, "Ошибка", "Мандатная метка просвоена " +QString::number(l_deleteMandatoryMark.size())+" мандатным группам. \n Смените метку этих групп перед удалением.");
        return;
    }
    else
    {
        if(!l_deleteMandatoryMark.exec("DELETE FROM \"mandatoryMarks\" WHERE \"mandatoryMarkId\" = "+QString::number(l_nCurrentId)+";"))
        {
            qDebug() << "Unable to delete Mandatory mark. SQL Error: " << l_deleteMandatoryMark.lastError() << l_deleteMandatoryMark.lastQuery();
            return;
        }
        else
        {
            QMessageBox::information(this, "Удаление мандатной метки", "Мандатная метка \""+l_strCurrentDescription+"\" удалена");
            fUpdateModels();
        }
    }
}

