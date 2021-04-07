#include "datacryptor.h"
#include <QDebug>
#include <math.h>
DataCryptor::DataCryptor(QObject *parent) : QObject(parent)
{

}
//Функция шифрования данных
QString DataCryptor::Encrypt(QString str)
{
    QString first;
    QString second;
    QString third;
    QString fourth;
    //Меняем символы местами
    for (int i=0;i<str.length();i++) {
        int disp = i+2;
        if(disp<str.length())
        {
            first +=str[disp];
        }
        else {
            first+=str[i-2];
        }
    }
    //берем часть символов справа и слева и соединяем их
    second = first.right(first.length()/3)+first.left(first.length()/3);
    //Шифр 1:
    for (int i=0; i<second.length();i++)
    {
        int ascii_result=ASCIIValidate(second[i].toLatin1()+log(second.length()));
        third +=(QChar)ascii_result;

    }
     //Шифр 2:
    for(int i=0; i<third.length(); i++)
    {
    fourth +=(QChar)ASCIIValidate(third[i].toLatin1()+sqrt(third.length()));
    }

    return fourth;


}

int DataCryptor::ASCIIValidate(int s)
{
    if(s<127 && s>33)
    {
        return s;
    }
    else if (s>127) {
        return (s-127)+32;
    }
    else return s+33;


}
