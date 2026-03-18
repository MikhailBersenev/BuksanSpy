#include "CAccessManager.h"
#include "Loggerd.h"
#include <QString>

CAccessManager::CAccessManager(QObject *parent) : QObject(parent)
{
    LOG_TRACE_MSG("CAccessManager constructed");
}

bool CAccessManager::fCheckRight(QString strUsername, int nRight)
{
    m_pMainQuery = new QSqlQuery;
    m_pMainQuery->prepare("SELECT rights.\"usersControl\", rights.\"addDevice\", rights.\"editDevice\", rights.\"deleteDevice\",  "
                       "rights.\"alertsView\", rights.\"alertsDelete\", rights.\"generalSettingsView\", rights.\"generalSettingsChange\","
                       "rights.\"videosView\", rights.\"videosDecrypt\", rights.\"videosDelete\", "
                       " users.username  FROM users, rights WHERE users.rights = rights.\"rightId\" AND users.username = :username;");
    m_pMainQuery->bindValue(":username", strUsername);
    if(!m_pMainQuery->exec())
    {
        LOG_CRITICAL_MSG((QStringLiteral("CAccessManager fCheckRight query failed: ") + m_pMainQuery->lastError().text() + QLatin1Char(' ') + m_pMainQuery->lastQuery()).toStdString());
    }
    m_pMainQuery->first();
    if(m_pMainQuery->isNull(0))
    {
        LOG_INFO_MSG((QStringLiteral("CAccessManager: user not found: ") + strUsername).toStdString());
        return false;
    }
    else
    {
        if(!m_pMainQuery->value(nRight).toBool())
        {
            return false;
        }
        else
        {
            return true;
        }
        delete m_pMainQuery;
    }
}

QString CAccessManager::fGetMandatoryGroup(QString strUsername) //Метод получения ID группы по логину
{
    m_pMainQuery = new QSqlQuery;
    m_pMainQuery->prepare("SELECT users.username, users.rights, rights.description FROM users, rights WHERE users.username = :username AND users.rights = rights.\"rightId\";");
    m_pMainQuery->bindValue(":username", strUsername);
    if(!m_pMainQuery->exec())
    {
        LOG_CRITICAL_MSG((QStringLiteral("Unable to get mandatory group: ") + m_pMainQuery->lastError().text() + QLatin1Char(' ') + m_pMainQuery->lastQuery()).toStdString());
    }
    m_pMainQuery->first();
    QString l_strResult = m_pMainQuery->value(2).toString();
    delete m_pMainQuery;
    return l_strResult;
}

qint64 CAccessManager::fGetAccessLevel(QString strUsername)
{ //Получить уровень допуска
    m_pMainQuery = new QSqlQuery;
    qint64 l_nResult;
    m_pMainQuery->prepare("SELECT \"userId\", username, \"accessLevel\" FROM \"vUsers\" WHERE username = '"+strUsername+"';");
    if(!m_pMainQuery->exec())
    {
        LOG_CRITICAL_MSG((QStringLiteral("Unable to check access level: ") + m_pMainQuery->lastError().text() + QLatin1Char(' ') + m_pMainQuery->lastQuery()).toStdString());
    }
    m_pMainQuery->first();
    l_nResult = m_pMainQuery->value(2).toInt();
    delete m_pMainQuery;
    return l_nResult;
}


