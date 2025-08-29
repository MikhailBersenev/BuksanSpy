#include "CCheckString.h"
CCheckString::CCheckString(QObject *parent) : QObject(parent)
{

}
bool CCheckString::CheckPassword(QString Password, QString PasswordRpt)
{   bool ok=false;
    QString AlphaBet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(Password==PasswordRpt) //Проверка на совпадение
    {
        if(Password.length()>=8) //Не меньше 8 символов
        {
            if(!Password.toFloat()) { //цифры буквы
                for (int i=0; i<Password.length(); i++ ) {

                    for (int counter=0;counter<25;counter++ ) {
                        if(Password[i] == AlphaBet[counter]) {
                            ok = true; //если есть заглавная ставим ок
                            break;
                        }
                    }
                    if(ok==true) {
                        break; //если ок то прерываем весь цикл
                    }


                }
                if(ok==true) {
                    return true;
                }
                else
                {
                    ErrorDesc = "Пароль должен содержать строчные и заглавные буквы латинского алфавита";
                    return false;
                }
            }
            else
            {
                ErrorDesc = "Пароль должен содержать не только цифры";
                return false;
            }
        }
        else
        {
            ErrorDesc = "Пароль меньше 8 символов";
            return false;
        }

    }
    else {
        ErrorDesc = "Пароли не совпадают";
        return false;
    }
}
bool CCheckString::CheckUserExist(QString username)
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

bool CCheckString::CheckMail(QString email)
{
   QRegularExpression rxp("(mail\\.ru|yandex\\.ru|gmail\\.com|outlook\\.com|yahoo\\.com|icloud\\.com|zoho\\.com|rambler\\.ru|inbox\\.com|aol\\.com)");
   QList <QString> domainlist;
    QMutableListIterator <QString> it(domainlist);
    QString name;
    QString domain;
    int domain_count;
    name = email.left(email.indexOf('@'));
    domain_count = email.length();
    domain_count = domain_count-name.length();
    domain = email.right(domain_count);
    bool matches = rxp.match(domain).hasMatch();
    if(name.length()>=4)
    {
        if(!matches)
        {
            ErrorDesc = "Недопустимый провайдер email";
            return false;
        }
        else
        {
        return true;
        }
    }
    else {
        ErrorDesc = "Длина имени пользователя должна составлять не менее 4 символов без учета домена";
        return false;
    }
}
