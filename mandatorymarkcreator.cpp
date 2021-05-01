#include "mandatorymarkcreator.h"
#include "ui_mandatorymarkcreator.h"
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
MandatoryMarkCreator::MandatoryMarkCreator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MandatoryMarkCreator)
{
    ui->setupUi(this);
}

MandatoryMarkCreator::~MandatoryMarkCreator()
{
    delete ui;
}

void MandatoryMarkCreator::on_buttonBox_accepted()
{
    QSqlQuery CreateMandatoryMark;
    CreateMandatoryMark.exec("SELECT description FROM \"mandatoryMarks\" WHERE description = '"+ui->MarkName_lineEdit->text()+"';");
    CreateMandatoryMark.first();
    if(!ui->MarkName_lineEdit->text().isEmpty() && ui->accesslevel_Slider->sliderPosition()>0 && CreateMandatoryMark.isNull(0))
    {
        if(!CreateMandatoryMark.exec("INSERT INTO \"mandatoryMarks\" (description, \"accessLevel\") VALUES ('"+ui->MarkName_lineEdit->text()+"', "+QString::number(ui->accesslevel_Slider->sliderPosition())+");"))
        {
            qDebug() << "Unable to create a mac mark! SQL Error: " << CreateMandatoryMark.lastError() << CreateMandatoryMark.lastQuery();
            return;
        }
        else {
            QMessageBox::information(this, "Создание мандатной метки", "Мандатная метка \""+ui->MarkName_lineEdit->text()+"\" успешно создана");
        }

    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Не удалось создать мандатную метку, Проверьте введенные данные.");
    }

}

void MandatoryMarkCreator::on_accesslevel_Slider_sliderMoved(int position)
{
    ui->Currentposition_label->setText("Текущий уровень: "+QString::number(position));
}
