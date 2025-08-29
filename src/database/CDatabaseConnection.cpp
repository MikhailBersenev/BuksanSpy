#include "CDatabaseConnection.h"
#include "security/CUsers.h"
#include "ui/CEventLog.h"
#include "ui/CMandatoryGroups.h"
#include <QDebug>

CDatabaseConnection::CDatabaseConnection(QObject *parent) : QObject(parent)
{
}

bool CDatabaseConnection::fCreateConnection(QString strHostName, QString strDBName, QString strUserName, QString strPassword, int nPort)
{
    m_db = QSqlDatabase::addDatabase("QPSQL"); //Задание драйвера
    m_db.setDatabaseName(strDBName); //Имя пользователя
    m_db.setHostName(strHostName);   //Хост
    m_db.setPort(nPort);
    m_db.setUserName(strUserName);   //Пользователь
    m_db.setPassword(strPassword);   //Пароль
    qDebug() << "UserName " << strUserName << " " << strDBName;
    
    //Проверка на возможность соединения и соединение
    if(!m_db.open()) {
        qDebug() << "Unable to create connection" << m_db.lastError();
        return false;
    }
    else
    {
        m_db.driver()->subscribeToNotification("insert_users_notf");
        m_pSendAlert = new CSendAlert; //Создание динамического объекта посылателя событий
        m_pSendAlert->fPrepare(); //Подготовка события
        m_pSendAlert->fSetUser(strUserName);
        m_pSendAlert->fSetSignature(1);                 //Присвоение сигнатуры события
        m_pSendAlert->fSend();                          //Отправка события
        delete m_pSendAlert; //Удаление динамического объекта посылателя сообщений
        return true;
    }
}


