#include "CAuthorization.h"
#include "ui_CAuthorization.h"
#include <QtWidgets>
#include <QSettings>
#include "db/CDataCryptor.h"
#include "CBuksanSpyApp.h"
#include "db/CDatabaseConnectionPSQL.h"
#include <QMessageBox>
#include <QDebug>

CAuthorization::CAuthorization(QWidget *parent) :
    QDialog(parent),
    m_pUi(new Ui::CAuthorization),
    m_pEventHelper(nullptr)
{
    m_pUi->setupUi(this);
}

CAuthorization::~CAuthorization()
{
    delete m_pUi;
}

void CAuthorization::fAuth(QString strUsername)
{
    m_pMainQuery = new QSqlQuery; //Динамическое создание объекта запроса
    m_pMainQuery->prepare("SELECT * FROM \"vUsers\" WHERE username = :username;"); //Подготовка запроса
    m_pMainQuery->bindValue(":username", strUsername); //Берем логин из поля
    if(!m_pMainQuery->exec()) //Выполнение запроса
    {
        qDebug() << "Unable to execute query" << m_pMainQuery->lastQuery() << m_pMainQuery->lastError();
    }
    m_pMainQuery->first();
    if(m_pMainQuery->value(5).toInt()==-1)
    {
        QMessageBox::critical(this, "Authorization error", "Account "+m_pMainQuery->value(1).toString()+" is banned.");
    }
    else
    {
        close(); //Закрытие формы авторизации
        
        // Инициализация CEventHelper один раз
        if (!m_pEventHelper) {
            m_pEventHelper = new CEventHelper(this);
        }
        
        // Отправка события аутентификации пользователя
        m_pEventHelper->fSendUserAuthEvent(strUsername);

        m_dashBoard.m_strUsername = strUsername;
        m_dashBoard.fSetTitle();
        m_pCheck = new CCheckConnection(this);
        m_pCheck->m_strUsername = strUsername;
        // m_pCheck->start();
        m_dashBoard.show(); //Отображение главной формы
    }
}

void CAuthorization::on_TryLogin_Button_clicked()
{
    CDataCryptor l_passwordCrypt;
    if(!(m_pUi->Login_Edit->text().isEmpty() or m_pUi->Password_Edit->text().isEmpty() or m_pUi->Host_Edit->text().isEmpty() or m_pUi->Port_Edit->text().isEmpty() or m_pUi->DataBase_Edit->text().isEmpty()))
    {
        // Подготовка структуры параметров подключения
        CDatabaseConnection::SDBConnection l_connection;
        l_connection.strHostName = m_pUi->Host_Edit->text();
        l_connection.strDBName = m_pUi->DataBase_Edit->text();
        l_connection.strUserName = m_pUi->Login_Edit->text();
        l_connection.strPassword = m_pUi->Password_Edit->text();
        l_connection.nPort = m_pUi->Port_Edit->text().toInt();
        
        if(!m_dbConnection.fCreateConnection(l_connection))
        {
            QMessageBox::critical(this, "Authorization error", m_dbConnection.m_db.lastError().databaseText());
        }
        else
        {
            // Инициализация CEventHelper один раз
            if (!m_pEventHelper) {
                m_pEventHelper = new CEventHelper(this);
            }
            
            // Отправка события подключения к серверу БД
            m_pEventHelper->fSendServerConnectEvent(m_pUi->Login_Edit->text());
            
            fAuth(m_pUi->Login_Edit->text());
            if(m_pUi->SaveLoginStrings_checkBox->isChecked())
            {
                fSaveSession();
            }
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning!", "Empty fields");
    }
}

void CAuthorization::on_ShowPassword_checkBox_stateChanged(int nArg1)
{ //Скрыть или показать пароль
    QLineEdit::EchoMode l_state = QLineEdit::Password;
    switch (nArg1) {
    case 0:
        l_state = QLineEdit::Password;
        break;
    case 2:
        l_state = QLineEdit::Normal;
        break;
    }
    m_pUi->Password_Edit->setEchoMode(l_state);
}

void CAuthorization::fSaveSession()
{
    QSettings l_settings;
    l_settings.beginGroup("/SessionData");
    l_settings.setValue("/host", m_pUi->Host_Edit->text());
    l_settings.setValue("/DBName", m_pUi->DataBase_Edit->text());
    l_settings.setValue("/Port", m_pUi->Port_Edit->text());
    l_settings.setValue("/UserName", m_pUi->Login_Edit->text());
    l_settings.setValue("/UserPassword", m_pUi->Password_Edit->text());
    l_settings.setValue("/timestamp", QDateTime::currentSecsSinceEpoch());
    l_settings.endGroup();
}
