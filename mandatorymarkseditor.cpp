#include "mandatorymarkseditor.h"
#include "ui_mandatorymarkseditor.h"
#include "mandatorymarkcreator.h"
#include <QtSql>
#include <QMessageBox>
#include "accessmanager.h"
MandatoryMarksEditor::MandatoryMarksEditor(QWidget *parent, QString user) :
    QDialog(parent),
    ui(new Ui::MandatoryMarksEditor)
{
    ui->setupUi(this);
    username = user;
    UpdateModels();
}

MandatoryMarksEditor::~MandatoryMarksEditor()
{
    delete ui;
}

void MandatoryMarksEditor::UpdateModels()
{
    MandatoryMarks_model.setQuery("SELECT * FROM \"mandatoryMarks\" ORDER BY \"accessLevel\" ASC;");
    ui->MandatoryMarks_listView->setModel(&MandatoryMarks_model);
    ui->MandatoryMarks_listView->setModelColumn(1);


}

void MandatoryMarksEditor::on_addMandatoryMark_pushButton_clicked()
{
 MandatoryMarkCreator *creator = new MandatoryMarkCreator(this);
 creator->setModal(true);
 creator->exec();
 delete creator;
}

void MandatoryMarksEditor::on_DeleteMandatoryMark_pushButton_clicked()
{
    QSqlQuery DeleteMandatoryMark;
   const int currentId = MandatoryMarks_model.data(MandatoryMarks_model.index(ui->MandatoryMarks_listView->currentIndex().row(),0)).toInt();
   const QString currentDescription = MandatoryMarks_model.data(MandatoryMarks_model.index(ui->MandatoryMarks_listView->currentIndex().row(),1)).toString();
    if(!DeleteMandatoryMark.exec("DELETE FROM \"mandatoryMarks\" WHERE \"mandatoryMarkId\" = "+QString::number(currentId)+";"))
       {
        qDebug() << "Unable to delete Mandatory mark. SQL Error: " << DeleteMandatoryMark.lastError() << DeleteMandatoryMark.lastQuery();
        return;
    }
    else
    {
        QMessageBox::information(this, "Удаление мандатной метки", "Мандатная метка \""+currentDescription+"\" удалена");
    }

}
