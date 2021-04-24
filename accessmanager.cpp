#include "accessmanager.h"
#include <QDebug>
AccessManager::AccessManager(QObject *parent) : QObject(parent)
{

}

bool AccessManager::checkright(QString username, int right)
{
    MainQuery = new QSqlQuery;
    MainQuery->prepare("SELECT rights.\"usersControl\", rights.\"addDevice\", rights.\"editDevice\", rights.\"deleteDevice\",  "
                       "rights.\"alertsView\", rights.\"alertsDelete\", rights.\"generalSettingsView\", rights.\"generalSettingsChange\","
                       "rights.\"videosView\", rights.\"videosDecrypt\", rights.\"videosDelete\", "
                       " users.username  FROM users, rights WHERE users.rights = rights.\"rightId\" AND users.username = :username;");
    MainQuery->bindValue(":username", username);
    if(!MainQuery->exec())
    {
        qDebug() << "Unable to create query!" << MainQuery->lastError() << MainQuery->lastQuery();
    }
    MainQuery->first();
    if(MainQuery->isNull(0))
    {
        qDebug() << "user doesn't exist";
        return false;
    }
    else
    {
        if(!MainQuery->value(right).toBool())
        {

            return false;
        }
        else
        {
            return true;
        }
        delete MainQuery;
    }



}

QString AccessManager::GetMandatoryGroup(QString username) //Метод получения ID группы по логину
{
    MainQuery = new QSqlQuery;
    MainQuery->prepare("SELECT users.username, users.rights, rights.description FROM users, rights WHERE users.username = :username AND users.rights = rights.\"rightId\";");
    MainQuery->bindValue(":username", username);
    if(!MainQuery->exec())
    {
        qDebug() << "Unable to get group Id" << MainQuery->lastError() << MainQuery->lastQuery();
    }
    MainQuery->first();
    QString result = MainQuery->value(2).toString();
    delete MainQuery;
    return result;
}

qint64 AccessManager::GetAccessLevel(QString username)
{ //Получить уровень допуска
    MainQuery = new QSqlQuery;
    qint64 result;
    MainQuery->prepare("SELECT users.\"userId\", users.username, rights.\"accessLevel\" FROM users INNER JOIN rights ON rights.\"rightId\" = users.rights WHERE username = '"+username+"';");
    if(!MainQuery->exec())
    {
        qDebug() << "Unable to check access level" << MainQuery->lastError() << MainQuery->lastQuery();
    }
    MainQuery->first();
    result = MainQuery->value(2).toInt();
    delete MainQuery;
    return result;
}


