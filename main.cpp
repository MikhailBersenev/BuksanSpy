#include "buksanspy.h"
#include "authorization.h"
#include "checkstring.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BuksanSpy w;
  // w.show();
    Authorization auth;
    auth.show();
    return a.exec();
}
