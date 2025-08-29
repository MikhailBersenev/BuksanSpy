#ifndef CDATACRYPTOR_H
#define CDATACRYPTOR_H

#include <QObject>

class CDataCryptor : public QObject
{
    Q_OBJECT
public:
    explicit CDataCryptor(QObject *parent = nullptr);
    QString Encrypt(QString str);
private:
int ASCIIValidate(int s);


signals:

};

#endif // CDATACRYPTOR_H
