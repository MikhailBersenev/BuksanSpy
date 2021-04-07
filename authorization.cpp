#include "authorization.h"
#include "ui_authorization.h"
#include <QtWidgets>
#include "datacryptor.h"
Authorization::Authorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authorization)
{
    ui->setupUi(this);
    connect(this, SIGNAL(expired()), this,  SLOT(attempts_expired()));
    Counter=0;
setWindowIcon(QIcon("./icon.png"));


}

Authorization::~Authorization()
{
    delete ui;
}

void Authorization::on_GoToSetupConnection_Button_clicked()
{
    //переход к форме настройки соединения
    SetupConnection_var.setModal(true);
    SetupConnection_var.exec();
}

void Authorization::on_TryLogin_Button_clicked()
{
    DataCryptor passwordCrypt;
    //Проверка на соедиение с базой данных
    if(!SetupConnection_var.db.open()) { //если нет то выводим сообщение и открываем форму настройки
        QMessageBox::warning(this, "Ошибка", "Отсутствует соединение с базой данных");
        SetupConnection_var.exec();
    }
    else
    {
        //Проверка на пустые поля
        if(!(ui->Login_Edit->text()=="" or ui->Password_Edit->text()==""))
        {
            MainQuery = new QSqlQuery; //Динамическое создание объекта запроса
            MainQuery->prepare("SELECT * FROM users WHERE username = :username;"); //Подготовка запроса
            MainQuery->bindValue(":username", ui->Login_Edit->text()); //Берем логин из поля
            if(!MainQuery->exec()) //Выполнение запроса
            {
                qDebug() << "Unable to execute query" << MainQuery->lastQuery() << MainQuery->lastError();
            }
            MainQuery->first();
            int current = QDateTime::currentSecsSinceEpoch();
            int bantime = current-MainQuery->value(7).toInt();
            if(!MainQuery->value(6).toBool() and bantime>1800 and !MainQuery->value(0).isNull()) {
                MainQuery->clear();
                MainQuery->prepare("UPDATE users SET active = true, bantimestamp=0 WHERE username = :username;");
                MainQuery->bindValue(":username", ui->Login_Edit->text());
                if(!MainQuery->exec())
                {
                    qDebug() << "Unable to unlock user" << MainQuery->lastError() << MainQuery->lastQuery();
                }
                SendAlert_var = new SendAlert(this); //отправка события
                SendAlert_var->prepare();
                SendAlert_var->setUser(ui->Login_Edit->text());
                SendAlert_var->setSignature(16);
                SendAlert_var->send();
                delete SendAlert_var;
                MainQuery->first();
            }
            if(ui->Login_Edit->text()==MainQuery->value(1).toString() and passwordCrypt.Encrypt(ui->Password_Edit->text())==MainQuery->value(2).toString() and MainQuery->value(6).toBool())
            {

                close(); //Закрытие формы авторизации
                SendAlert_var = new SendAlert; //Создание динамического объекта посылателя событий
                SendAlert_var->prepare(); //Подготовка события
                SendAlert_var->setUser(ui->Login_Edit->text()); //Присвоение имени пользователя
                SendAlert_var->setSignature(1);                 //Присвоение сигнатуры события
                SendAlert_var->send();                          //Отправка события
                delete SendAlert_var; //Удаление динамического объекта посылателя сообщений
                DashBoard.username = ui->Login_Edit->text();
                DashBoard.SetTitle();
                DashBoard.show(); //Отображение главной формы
            }
            else
            {

                QMessageBox::critical(this, "Ошибка", "Неверный пароль или у вас недостаточно прав для доступа");
                SendAlert_var = new SendAlert(this);
                SendAlert_var->prepare();
                SendAlert_var->setSignature(14);
                SendAlert_var->setUser(ui->Login_Edit->text());
                SendAlert_var->send();
                Counter++;
                if(Counter>5 && MainQuery->size() !=0)
                {
                    emit expired();
                }
                delete  SendAlert_var;
                delete MainQuery; //удаление динамического  объекта запроса
            }


        }
        else
        {
            QMessageBox::warning(this, "Внимание!", "Обнаружены пустые поля");
        }
    }
}

void Authorization::on_GotToRegistration_Button_clicked()
{
    if(!SetupConnection_var.db.open())
    {
        QMessageBox::warning(this, "Ошибка", "отсутствует соединение с базой данных");
        SetupConnection_var.exec();
    }
    else
    {
        Registration_var.setModal(true); //Задаем модальность формы
        Registration_var.exec(); //показываем форму
    }
}



void Authorization::on_quit_Button_clicked()
{
    QMessageBox::information(this, "Информация", "Программа будет закрыта");
    QApplication::quit();
}

void Authorization::attempts_expired()
{
    SendAlert_var = new SendAlert(this);
    SendAlert_var->prepare();
    SendAlert_var->setSignature(15);
    SendAlert_var->send();

    QMessageBox::warning(this, "Превышено число попыток ввода пароля", "Ваша учетная запись заблокирована на 1850 секунд");
    MainQuery = new QSqlQuery;
    MainQuery->prepare("UPDATE users SET active= :active, bantimestamp = :timestamp WHERE username = :username;");
    MainQuery->bindValue(":active", false);
    MainQuery->bindValue(":username", ui->Login_Edit->text());
    MainQuery->bindValue(":timestamp", QDateTime::currentSecsSinceEpoch());
    if(!MainQuery->exec())
    {
        qDebug() << "Unable to ban user" << MainQuery->lastError() << MainQuery->lastQuery();
    }
    SendAlert_var->prepare();
    SendAlert_var->setUser(ui->Login_Edit->text());
    SendAlert_var->setSignature(9);
    SendAlert_var->send();
    delete SendAlert_var;

}
