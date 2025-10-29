#include "CDataCryptor.h"
#include <QDebug>
#include <math.h>

CDataCryptor::CDataCryptor(QObject *parent) : QObject(parent)
{
}

//Функция шифрования данных
QString CDataCryptor::Encrypt(QString str)
{
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

int CDataCryptor::ASCIIValidate(int nS)
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
