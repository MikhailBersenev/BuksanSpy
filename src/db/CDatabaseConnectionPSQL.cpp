#include "CDatabaseConnectionPSQL.h"
#include <QDebug>
CDatabaseConnectionPSQL::CDatabaseConnectionPSQL(QObject *parent) : CDatabaseConnection(parent)
{
}

bool CDatabaseConnectionPSQL::fCreateConnection(SDBConnection& lConnection)
{
    m_db = QSqlDatabase::addDatabase("QPSQL"); //Задание драйвера
    m_db.setDatabaseName(lConnection.strDBName); //Имя базы данных
    m_db.setHostName(lConnection.strHostName);   //Хост
    m_db.setPort(lConnection.nPort);
    m_db.setUserName(lConnection.strUserName);   //Пользователь
    m_db.setPassword(lConnection.strPassword);   //Пароль
    qDebug() << "UserName " << lConnection.strUserName << " " << lConnection.strDBName;
    //Проверка на возможность соединения и соединение
    if(!m_db.open()) {
        qDebug() << "Unable to create connection" << m_db.lastError();
        return false;
    }
    else
    {
        m_db.driver()->subscribeToNotification("insert_users_notf");
        qDebug() << "PostgreSQL connection established " << m_db.hostName();
        return true;
    }
}


