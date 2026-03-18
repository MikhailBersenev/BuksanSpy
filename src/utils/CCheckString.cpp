#include "CCheckString.h"
#include "Loggerd.h"
#include <QString>

CCheckString::CCheckString(QObject *parent) : QObject(parent)
{
}

bool CCheckString::CheckUserExist(QString username)
{
    MainQuery = new QSqlQuery;
    MainQuery->prepare("SELECT username FROM users WHERE username = :username;");
    MainQuery->bindValue(":username", username);
    if(!MainQuery->exec())
    {
        LOG_CRITICAL_MSG((QStringLiteral("Unable to execute query (CCheckString) ") + MainQuery->lastError().text() + QLatin1Char(' ') + MainQuery->lastQuery()).toStdString());
    }
    MainQuery->first();
    if(MainQuery->isNull(0))
    {
        return false;
    }
    else {
        ErrorDesc = "Пользователь с таким именем уже существует";
        return true;
    }
    delete MainQuery;
}
