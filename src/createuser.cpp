#include "createuser.h"
#include "ui_createuser.h"
#include <QtWidgets>

CreateUser::CreateUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateUser)
{
    ui->setupUi(this);
    rightsModel.setQuery("SELECT description, \"rightId\" FROM rights;"); //Заполняем комбобокс
    ui->Rights_ComboBox->setModel(&rightsModel);

}

CreateUser::~CreateUser()
{
    delete ui;
}

void CreateUser::on_ShowPassword_CheckBox_stateChanged(int arg1)
{
    //Отображение или скрытие пароля
    Q_UNUSED(arg1);
    if(!ui->ShowPassword_CheckBox->isChecked())
    {
        ui->Password_Edit->setEchoMode(QLineEdit::Password);
        ui->RepeatPassword_Edit->setEchoMode(QLineEdit::Password);
    }
    else
    {
        ui->Password_Edit->setEchoMode(QLineEdit::Normal);
        ui->RepeatPassword_Edit->setEchoMode(QLineEdit::Normal);
    }
}

void CreateUser::on_Confirm_Button_clicked()
{
    CheckPassword = new CheckString(this);
    if(!(CheckPassword->CheckPassword(ui->Password_Edit->text(), ui->RepeatPassword_Edit->text())) or CheckPassword->CheckUserExist(ui->Login_Edit->text()))
    {
        QMessageBox::warning(this, "Внимание!", CheckPassword->ErrorDesc);
    }
    else
    {
        CreateUserQuery = new QSqlQuery;
        CreateUserQuery->prepare("INSERT INTO users (username, \"addDate\", rights) VALUES (:username, :date, :rights);");
        CreateUserQuery->bindValue(":username", ui->Login_Edit->text());
        CreateUserQuery->bindValue(":date", QDate::currentDate());
        CreateUserQuery->bindValue(":rights", ui->Rights_ComboBox->model()->index(ui->Rights_ComboBox->currentIndex(),1).data().toInt());
        if(!CreateUserQuery->exec())
        {
            qDebug() << "Unable to create a user" << CreateUserQuery->lastError() << CreateUserQuery->lastQuery();
            return;
        }
        if(!CreateUserQuery->exec("CREATE ROLE "+ui->Login_Edit->text()+" LOGIN  PASSWORD '"+ui->Password_Edit->text()+"' SUPERUSER INHERIT CREATEDB CREATEROLE REPLICATION;"))
        {
         qDebug() << "Unable to create a SQL role" << CreateUserQuery->lastError() << CreateUserQuery->lastQuery();
        }
        else
        {
            QMessageBox::information(this, "Создание нового пользователя", "Аккаунт создан");
            SendAlert_var = new SendAlert(this);
            SendAlert_var->prepare();
            SendAlert_var->setUser(ui->Login_Edit->text());
            SendAlert_var->setSignature(3);
            SendAlert_var->send();
            delete SendAlert_var;
            close();


        }
    }
}
