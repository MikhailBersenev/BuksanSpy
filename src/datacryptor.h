#ifndef DATACRYPTOR_H
#define DATACRYPTOR_H

#include <QObject>

class DataCryptor : public QObject
{
    Q_OBJECT
public:
    explicit DataCryptor(QObject *parent = nullptr);
    QString Encrypt(QString str);
private:
int ASCIIValidate(int s);


signals:

};

#endif // DATACRYPTOR_H
