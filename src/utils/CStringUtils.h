#ifndef CSTRINGUTILS_H
#define CSTRINGUTILS_H

#include <QObject>

class CStringUtils : public QObject
{
    Q_OBJECT
public:
    explicit CStringUtils(QObject *parent = nullptr);
    static  bool CheckPassword(QString Password, QString PasswordRpt, QString& ErrorDesc);
    static bool CheckMail(QString email, QString& ErrorDesc);
    static QString HashBuksan(QString str);
private:
    static int ASCIIValidate(int nS);

signals:
};

#endif // CSTRINGUTILS_H
