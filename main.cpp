#include "buksanspy.h"
#include "datacryptor.h" //!!!
#include "authorization.h"
#include "checkstring.h"
#include <QNetworkConfigurationManager>
#include "networkinfo.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //  BuksanSpy w;
 //  w.show();
    DataCryptor dc;
    QNetworkConfigurationManager nrd;
    qDebug() << nrd.isOnline();

    QString ahj= dc.Encrypt("VideoCapture");
    NetworkInfo ip;
    qDebug() << ip.GetIPAddress();
    Authorization auth;
    QTimer abc;
    auth.show();
    return a.exec();
}
