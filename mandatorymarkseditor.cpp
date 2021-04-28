#include "mandatorymarkseditor.h"
#include "ui_mandatorymarkseditor.h"
#include <QtSql>
MandatoryMarksEditor::MandatoryMarksEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MandatoryMarksEditor)
{
    ui->setupUi(this);
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
