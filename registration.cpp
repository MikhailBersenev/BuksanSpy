#include "registration.h"
#include "ui_registration.h"
#include "datacryptor.h"
#include <QtWidgets>
#include <QDate>
#include <QDebug>

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);

}

Registration::~Registration()
{
    delete ui;

}

void Registration::on_ShowPassword_CheckBox_stateChanged(int arg1)
{
    /*Обработчик для чекбокса (показать или скрыть пароль) */
    Q_UNUSED(arg1);
    if(ui->ShowPassword_CheckBox->isChecked()) {
        ui->Password_Edit->setEchoMode(QLineEdit::Normal);
        ui->RepeatPassword_Edit->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->Password_Edit->setEchoMode(QLineEdit::Password);
        ui->RepeatPassword_Edit->setEchoMode(QLineEdit::Password);
    }
}

void Registration::on_TryToRegister_Button_clicked()
{
    CheckStr_var = new CheckString(this);
    DataCryptor CryptPassword;
    if(ui->Login_Edit->text().isEmpty() or ui->Password_Edit->text().isEmpty() or ui->RepeatPassword_Edit->text().isEmpty())
    {
        QMessageBox::warning(this, "Внимание!", "Поля не могут быть пустыми");
    }
    else
    {


if(!(CheckStr_var->CheckPassword(ui->Password_Edit->text(), ui->RepeatPassword_Edit->text())) or CheckStr_var->CheckUserExist(ui->Login_Edit->text()) or !CheckStr_var->CheckMail(ui->Email_Edit->text())) {
            QMessageBox::warning(this, "Внимание!", CheckStr_var->ErrorDesc);
        }
        else
        {
            CreateUser_Query = new QSqlQuery;
            CreateUser_Query->prepare("INSERT INTO users (username, password, email, \"addDate\", rights) VALUES (:username, :password, :email, :date, 2);");
            CreateUser_Query->bindValue(":username", ui->Login_Edit->text());
            CreateUser_Query->bindValue(":password", CryptPassword.Encrypt(ui->Password_Edit->text()));
            CreateUser_Query->bindValue(":email", ui->Email_Edit->text());
            CreateUser_Query->bindValue(":date", QDate::currentDate());
            if(!CreateUser_Query->exec())
            {
                qDebug() << "Unable to create new user " << CreateUser_Query->lastError() << CreateUser_Query->lastQuery();
            }
            else
            {
                QMessageBox::information(this, "Регистрация", "Аккаунт создан");
                SendAlert_var = new SendAlert; //Отправляем событие
                SendAlert_var->prepare();
                SendAlert_var->setUser(ui->Login_Edit->text());
                SendAlert_var->setSignature(3);
                SendAlert_var->send();
                delete SendAlert_var;
                close();
                //очистка полей при закрытии
                ui->Login_Edit->clear();
                ui->Password_Edit->clear();
                ui->RepeatPassword_Edit->clear();
                ui->ShowPassword_CheckBox->setChecked(false);
            }
            delete CreateUser_Query;


        }
    }
    delete CheckStr_var;
}
