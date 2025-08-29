#include "CAccessManager.h"
#include <QDebug>

CAccessManager::CAccessManager(QObject *parent) : QObject(parent)
{

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
        qDebug() << "Unable to create query!" << m_pMainQuery->lastError() << m_pMainQuery->lastQuery();
    }
    m_pMainQuery->first();
    if(m_pMainQuery->isNull(0))
    {
        qDebug() << "user doesn't exist";
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
        qDebug() << "Unable to get group Id" << m_pMainQuery->lastError() << m_pMainQuery->lastQuery();
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
        qDebug() << "Unable to check access level" << m_pMainQuery->lastError() << m_pMainQuery->lastQuery();
    }
    m_pMainQuery->first();
    l_nResult = m_pMainQuery->value(2).toInt();
    delete m_pMainQuery;
    return l_nResult;
}


