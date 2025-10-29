#include "CUserCheck.h"
#include <QDebug>

CUserCheck::CUserCheck(QObject *parent) : QObject(parent)
{
}

bool CUserCheck::CheckUserExist(QString username)
{
    MainQuery = new QSqlQuery;
    MainQuery->prepare("SELECT username FROM users WHERE username = :username;");
    MainQuery->bindValue(":username", username);
    if(!MainQuery->exec())
    {
        qDebug() << "Unable to create query" << MainQuery->lastError() << MainQuery->lastQuery();
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
