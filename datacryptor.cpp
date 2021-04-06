#include "datacryptor.h"
#include <QDebug>
DataCryptor::DataCryptor(QObject *parent) : QObject(parent)
{

}
//Функция шифрования данных
QString DataCryptor::Encrypt(QString str)
{
 QString first;
 QString second;
 //Меняем символы местами
 for (int i=0;i<str.length();i++) {
     int disp = i+2;
     qDebug() << disp;
 if(disp<str.length())
 {
   first +=str[disp];
 }
 else {
 first+=str[i-2];
 }
 }
 second = first.right(first.length()/3)+first.left(first.length()/3);
qDebug() << first;
qDebug() << second;




}
