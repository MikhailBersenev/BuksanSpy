#include "authorization.h"
#include "ui_authorization.h"
#include <QtWidgets>
#include "datacryptor.h"
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



void Authorization::on_TryLogin_Button_clicked()
{
    DataCryptor passwordCrypt;
    DataBaseConnection dbConnection;
    if(!(ui->Login_Edit->text().isEmpty() or ui->Password_Edit->text().isEmpty()))
    {
        if(!dbConnection.CreateConnection(ui->Host_Edit->text(), ui->DataBase_Edit->text(), ui->Login_Edit->text(), ui->Password_Edit->text(), ui->Port_Edit->text().toInt()))
        {
            QMessageBox::critical(this, "Ошибка авторизации", dbConnection.db.lastError().databaseText());
        }
        else
        {
            MainQuery = new QSqlQuery; //Динамическое создание объекта запроса
            MainQuery->prepare("SELECT * FROM \"vUsers\" WHERE username = :username;"); //Подготовка запроса
            MainQuery->bindValue(":username", ui->Login_Edit->text()); //Берем логин из поля
            if(!MainQuery->exec()) //Выполнение запроса
            {
                qDebug() << "Unable to execute query" << MainQuery->lastQuery() << MainQuery->lastError();
            }
            MainQuery->first();
            if(MainQuery->value(5).toInt()==-1)
            {
                QMessageBox::critical(this, "Ошибка авторизации", "Аккаунт "+MainQuery->value(1).toString()+" заблокирован");
            }
            else
            {
                close(); //Закрытие формы авторизации
                for (int i=1;i<=2;++i) {
                    SendAlert_var = new SendAlert; //Создание динамического объекта посылателя событий
                    SendAlert_var->prepare(); //Подготовка события
                    SendAlert_var->setUser(ui->Login_Edit->text()); //Присвоение имени пользователя
                    SendAlert_var->setSignature(i);                 //Присвоение сигнатуры события
                    SendAlert_var->send();                          //Отправка события
                    delete SendAlert_var; //Удаление динамического объекта посылателя сообщений

                }
                DashBoard.username = ui->Login_Edit->text();
                DashBoard.SetTitle();
                check = new CheckConnection(this);
                check->username = ui->Login_Edit->text();
                // check->start();
                DashBoard.show(); //Отображение главной формы
            }
        }
    }
    else
    {
        QMessageBox::warning(this, "Внимание!", "Обнаружены пустые поля");
    }

}




