#include "authorization.h"
#include "ui_authorization.h"
#include <QtWidgets>
#include <QSettings>
#include "datacryptor.h"
#include <buksanspyapp.h>
#include "databaseconnection.h"
Authorization::Authorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authorization)
{
    ui->setupUi(this);

}

Authorization::~Authorization()
{
    delete ui;
}

void Authorization::Auth(QString username)
{
    MainQuery = new QSqlQuery; //Динамическое создание объекта запроса
    MainQuery->prepare("SELECT * FROM \"vUsers\" WHERE username = :username;"); //Подготовка запроса
    MainQuery->bindValue(":username", username); //Берем логин из поля
    if(!MainQuery->exec()) //Выполнение запроса
    {
        qDebug() << "Unable to execute query" << MainQuery->lastQuery() << MainQuery->lastError();
    }
    MainQuery->first();
    if(MainQuery->value(5).toInt()==-1)
    {
        QMessageBox::critical(this, "Ошибка авторизации", "Аккаунт "+MainQuery->value(1).toString()+" заблокирован.");
    }
    else
    {
        close(); //Закрытие формы авторизации
        SendAlert_var = new SendAlert; //Создание динамического объекта посылателя событий
        SendAlert_var->prepare(); //Подготовка события
        SendAlert_var->setUser(ui->Login_Edit->text()); //Присвоение имени пользователя
        SendAlert_var->setSignature(2);                 //Присвоение сигнатуры события
        SendAlert_var->send();                          //Отправка события
        delete SendAlert_var; //Удаление динамического объекта посылателя сообщений


        DashBoard.username = ui->Login_Edit->text();
        DashBoard.SetTitle();
        check = new CheckConnection(this);
        check->username = ui->Login_Edit->text();
        // check->start();
        DashBoard.show(); //Отображение главной формы
    }
}



void Authorization::on_TryLogin_Button_clicked()
{
    DataCryptor passwordCrypt;
    if(!(ui->Login_Edit->text().isEmpty() or ui->Password_Edit->text().isEmpty() or ui->Host_Edit->text().isEmpty() or ui->Port_Edit->text().isEmpty() or ui->DataBase_Edit->text().isEmpty()))
    {
        if(!dbConnection.CreateConnection(ui->Host_Edit->text(), ui->DataBase_Edit->text(), ui->Login_Edit->text(), ui->Password_Edit->text(), ui->Port_Edit->text().toInt()))
        {
            QMessageBox::critical(this, "Ошибка авторизации", dbConnection.db.lastError().databaseText());
        }
        else
        {
            Auth(ui->Login_Edit->text());
            if(ui->SaveLoginStrings_checkBox->isChecked())
            {
                SaveSession();
            }
        }
    }
    else
    {
        QMessageBox::warning(this, "Внимание!", "Обнаружены пустые поля");
    }

}





void Authorization::on_ShowPassword_checkBox_stateChanged(int arg1)
{ //Скрыть или показать пароль
    QLineEdit::EchoMode state = QLineEdit::Password;
    switch (arg1) {
    case 0:
        state = QLineEdit::Password;
        break;
    case 2:
        state = QLineEdit::Normal;
        break;
    }
    ui->Password_Edit->setEchoMode(state);
}

void Authorization::SaveSession()
{
    //Сохранение сессии
    QSettings *AppSettings = BuksanSpyApp::theApp()->settings();
    AppSettings->beginGroup("/SessionData");
    AppSettings->setValue("/host", ui->Host_Edit->text());
    AppSettings->setValue("/DBName", ui->DataBase_Edit->text());
    AppSettings->setValue("/Port", ui->Port_Edit->text());
    AppSettings->setValue("/UserName", ui->Login_Edit->text());
    AppSettings->setValue("/UserPassword", ui->Password_Edit->text());
    AppSettings->setValue("/timestamp", QDateTime::currentSecsSinceEpoch());
    AppSettings->endGroup();
}
