#include "CCreateUser.h"
#include "ui_CCreateUser.h"
#include <QtWidgets>
#include <QMessageBox>
#include <QDebug>
#include <QDate>

CCreateUser::CCreateUser(QWidget *parent) :
    QDialog(parent),
    m_pUi(new Ui::CCreateUser),
    m_pCreateUserQuery(nullptr),
    m_pEventHelper(nullptr)
{
    m_pUi->setupUi(this);
    m_rightsModel.setQuery("SELECT description, \"rightId\" FROM rights;"); //Заполняем комбобокс
    m_pUi->Rights_ComboBox->setModel(&m_rightsModel);
}

CCreateUser::~CCreateUser()
{
    delete m_pUi;
}

void CCreateUser::on_ShowPassword_CheckBox_stateChanged(int nArg1)
{
    //Отображение или скрытие пароля
    Q_UNUSED(nArg1);
    if(!m_pUi->ShowPassword_CheckBox->isChecked())
    {
        m_pUi->Password_Edit->setEchoMode(QLineEdit::Password);
        m_pUi->RepeatPassword_Edit->setEchoMode(QLineEdit::Password);
    }
    else
    {
        m_pUi->Password_Edit->setEchoMode(QLineEdit::Normal);
        m_pUi->RepeatPassword_Edit->setEchoMode(QLineEdit::Normal);
    }
}

void CCreateUser::on_Confirm_Button_clicked()
{
    // Проверка пароля через CStringUtils (статический метод)
    QString l_strError;
    if(!CStringUtils::CheckPassword(m_pUi->Password_Edit->text(), m_pUi->RepeatPassword_Edit->text(), l_strError))
    {
        QMessageBox::warning(this, "Warning!", l_strError);
        return;
    }
    
    // Проверка существования пользователя через CUserCheck (нужен доступ к БД)
    m_pUserCheck = new CUserCheck(this);
    if(m_pUserCheck->CheckUserExist(m_pUi->Login_Edit->text()))
    {
        QMessageBox::warning(this, "Warning!", m_pUserCheck->ErrorDesc);
        delete m_pUserCheck;
        return;
    }
    delete m_pUserCheck;
    
    // Если все проверки прошли, создаем пользователя
    if (!m_pCreateUserQuery) {
        m_pCreateUserQuery = new QSqlQuery;
    }
        m_pCreateUserQuery->prepare("INSERT INTO users (username, \"addDate\", rights) VALUES (:username, :date, :rights);");
        m_pCreateUserQuery->bindValue(":username", m_pUi->Login_Edit->text());
        m_pCreateUserQuery->bindValue(":date", QDate::currentDate());
        m_pCreateUserQuery->bindValue(":rights", m_pUi->Rights_ComboBox->model()->index(m_pUi->Rights_ComboBox->currentIndex(),1).data().toInt());
        if(!m_pCreateUserQuery->exec())
        {
            qDebug() << "Unable to create a user" << m_pCreateUserQuery->lastError() << m_pCreateUserQuery->lastQuery();
            return;
        }
        if(!m_pCreateUserQuery->exec("CREATE ROLE "+m_pUi->Login_Edit->text()+" LOGIN  PASSWORD '"+m_pUi->Password_Edit->text()+"' SUPERUSER INHERIT CREATEDB CREATEROLE REPLICATION;"))
        {
         qDebug() << "Unable to create a SQL role" << m_pCreateUserQuery->lastError() << m_pCreateUserQuery->lastQuery();
        }
        else
        {
            QMessageBox::information(this, "User creation", "Account created successfully");
            
            // Инициализация и отправка события регистрации пользователя
            if (!m_pEventHelper) {
                m_pEventHelper = new CEventHelper(this);
            }
            m_pEventHelper->fSendUserRegisterEvent(m_pUi->Login_Edit->text());
            
            close();
        }
}
