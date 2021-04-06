#include "buksanspy.h"
#include "datacryptor.h" //!!!
#include "authorization.h"
#include "checkstring.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BuksanSpy w;
  // w.show();
    DataCryptor dc;
    dc.Encrypt("astralinuxthebestdistroнахой");
    Authorization auth;
    auth.show();
    return a.exec();
}
