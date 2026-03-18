#include "CStringUtils.h"
#include "Loggerd.h"
#include <QRegularExpression>
#include <QString>

CStringUtils::CStringUtils(QObject *parent)
    : QObject{parent}
{
    LOG_TRACE_MSG("CStringUtils constructed");
}

bool CStringUtils::CheckPassword(QString Password, QString PasswordRpt, QString& ErrorDesc)
{
    bool ok=false;
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
                    LOG_TRACE_MSG("CStringUtils::CheckPassword OK");
                    return true;
                }
                else
                {
                    ErrorDesc = "Пароль должен содержать строчные и заглавные буквы латинского алфавита";
                    LOG_DEBUG_MSG("CStringUtils::CheckPassword failed: need mixed case");
                    return false;
                }
            }
            else
            {
                ErrorDesc = "Пароль должен содержать не только цифры";
                LOG_DEBUG_MSG("CStringUtils::CheckPassword failed: digits only");
                return false;
            }
        }
        else
        {
            ErrorDesc = "Пароль меньше 8 символов";
            LOG_DEBUG_MSG("CStringUtils::CheckPassword failed: too short");
            return false;
        }

    }
    else {
        ErrorDesc = "Пароли не совпадают";
        LOG_DEBUG_MSG("CStringUtils::CheckPassword failed: mismatch");
        return false;
    }
}

bool CStringUtils::CheckMail(QString email, QString& ErrorDesc)
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
            LOG_DEBUG_MSG("CStringUtils::CheckMail failed: bad domain");
            return false;
        }
        else
        {
            LOG_TRACE_MSG("CStringUtils::CheckMail OK");
            return true;
        }
    }
    else {
        ErrorDesc = "Длина имени пользователя должна составлять не менее 4 символов без учета домена";
        LOG_DEBUG_MSG("CStringUtils::CheckMail failed: short local part");
        return false;
    }
}

QString CStringUtils::HashBuksan(QString str)
{
    LOG_TRACE_MSG((QStringLiteral("CStringUtils::HashBuksan len=") + QString::number(str.length())).toStdString());
    QString l_strFirst;
    QString l_strSecond;
    QString l_strThird;
    QString l_strFourth;

    //Меняем символы местами
    for (int i = 0; i < str.length(); i++) {
        int l_nDisp = i + 2;
        if(l_nDisp < str.length())
        {
            l_strFirst += str[l_nDisp];
        }
        else {
            l_strFirst += str[i-2];
        }
    }

    //берем часть символов справа и слева и соединяем их
    l_strSecond = l_strFirst.right(l_strFirst.length()/3) + l_strFirst.left(l_strFirst.length()/3);

    //Шифр 1:
    for (int i = 0; i < l_strSecond.length(); i++)
    {
        int l_nAsciiResult = ASCIIValidate(l_strSecond[i].toLatin1() + log(l_strSecond.length()));
        l_strThird += (QChar)l_nAsciiResult;
    }

    //Шифр 2:
    for(int i = 0; i < l_strThird.length(); i++)
    {
        l_strFourth += (QChar)ASCIIValidate(l_strThird[i].toLatin1() + sqrt(l_strThird.length()));
    }

    return l_strFourth;
}

QString CStringUtils::GetAppName()
{
    const QString sAppName = "BuksanSpy";
    LOG_INFO_MSG(sAppName.toStdString());
    return sAppName;

}

QString CStringUtils::GetAppCopyright()
{
    const QString sAppCopyright = "Mikhail Bersenev © 2021-2026. All rights Reserved.";
    LOG_INFO_MSG(sAppCopyright.toStdString());
    return sAppCopyright;
}

QString CStringUtils::GetAppVersion()
{
    const QString sVersion = "21.5";
    LOG_INFO_MSG(sVersion.toStdString());
    return sVersion;
}

int CStringUtils::ASCIIValidate(int nS)
{
    if(nS < 127 && nS > 33)
    {
        return nS;
    }
    else if (nS > 127) {
        return (nS - 127) + 32;
    }
    else return nS + 33;
}

