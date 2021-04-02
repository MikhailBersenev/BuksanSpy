#ifndef CHECKSTRING_H
#define CHECKSTRING_H
#include <QtSql>
#include <QObject>

class CheckString : public QObject
{
    Q_OBJECT
public:
    explicit CheckString(QObject *parent = nullptr);
    bool CheckPassword(QString Password, QString PasswordRpt);
    bool CheckForLetters(QString StringForCheck);
    bool CheckUserExist(QString username);
    QString ErrorDesc;
    bool CheckMail(QString email);

private:
QSqlQuery *MainQuery;

};

#endif // CHECKSTRING_H
