#include "CMandatoryMarkCreator.h"
#include "ui_CMandatoryMarkCreator.h"
#include <QtSql>
#include <QDebug>
#include <QMessageBox>

CMandatoryMarkCreator::CMandatoryMarkCreator(QWidget *parent) :
    QDialog(parent),
    m_pUi(new Ui::CMandatoryMarkCreator)
{
    m_pUi->setupUi(this);
}

CMandatoryMarkCreator::~CMandatoryMarkCreator()
{
    delete m_pUi;
}

void CMandatoryMarkCreator::on_buttonBox_accepted()
{
    QSqlQuery l_createMandatoryMark;
    l_createMandatoryMark.exec("SELECT description FROM \"mandatoryMarks\" WHERE description = '"+m_pUi->MarkName_lineEdit->text()+"';");
    l_createMandatoryMark.first();
    if(!m_pUi->MarkName_lineEdit->text().isEmpty() && m_pUi->accesslevel_Slider->sliderPosition()>0 && l_createMandatoryMark.isNull(0))
    {
        if(!l_createMandatoryMark.exec("INSERT INTO \"mandatoryMarks\" (description, \"accessLevel\") VALUES ('"+m_pUi->MarkName_lineEdit->text()+"', "+QString::number(m_pUi->accesslevel_Slider->sliderPosition())+");"))
        {
            qDebug() << "Unable to create a mac mark! SQL Error: " << l_createMandatoryMark.lastError() << l_createMandatoryMark.lastQuery();
            return;
        }
        else {
            QMessageBox::information(this, "Create mandate label", "Mandate label \""+m_pUi->MarkName_lineEdit->text()+"\" was successfully created");
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "Unable to create a mandate label. Please revise entered information.");
    }
}

void CMandatoryMarkCreator::on_accesslevel_Slider_sliderMoved(int position)
{
    m_pUi->Currentposition_label->setText("Current access level: "+QString::number(position));
}
