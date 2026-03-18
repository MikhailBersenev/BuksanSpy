#include "CDatabaseConnectionPSQL.h"
#include "Loggerd.h"
#include <QString>
CDatabaseConnectionPSQL::CDatabaseConnectionPSQL(QObject *parent) : CDatabaseConnection(parent)
{
    LOG_TRACE_MSG("CDatabaseConnectionPSQL constructed");
}

bool CDatabaseConnectionPSQL::fCreateConnection(SDBConnection& lConnection)
{
    m_db = QSqlDatabase::addDatabase("QPSQL"); //Задание драйвера
    m_db.setDatabaseName(lConnection.strDBName); //Имя базы данных
    m_db.setHostName(lConnection.strHostName);   //Хост
    m_db.setPort(lConnection.nPort);
    m_db.setUserName(lConnection.strUserName);   //Пользователь
    m_db.setPassword(lConnection.strPassword);   //Пароль
    LOG_INFO_MSG((QStringLiteral("PostgreSQL connecting user=") + lConnection.strUserName + QLatin1String(" db=") + lConnection.strDBName).toStdString());
    //Проверка на возможность соединения и соединение
    if(!m_db.open()) {
        LOG_CRITICAL_MSG((QStringLiteral("Unable to open PostgreSQL: ") + m_db.lastError().text()).toStdString());
        return false;
    }
    else
    {
        m_db.driver()->subscribeToNotification("insert_users_notf");
        LOG_INFO_MSG((QStringLiteral("PostgreSQL connection established, host=") + m_db.hostName()).toStdString());
        return true;
    }
}


