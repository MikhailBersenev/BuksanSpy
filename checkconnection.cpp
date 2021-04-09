#include "checkconnection.h"
#include <QNetworkConfigurationManager>
#include <QTimer>
#include "sendalert.h"
CheckConnection::CheckConnection(QObject *parent) : QThread(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(CheckInternet()));
    timer->setInterval(30000);
    timer->start();
}

CheckConnection::~CheckConnection()
{
    delete timer;
}

void CheckConnection::CheckInternet()
{
    if(!man->isOnline())
    {//Проверка соединения с Интернетом

        SendAlert *SendAlert_var = new SendAlert(this);
        SendAlert_var->prepare();
        SendAlert_var->setUser(username);
        SendAlert_var->setSignature(17);
        SendAlert_var->send();
        delete SendAlert_var;
    }
    else
    {
        SendAlert_var = new SendAlert(this);
        SendAlert_var->prepare();
        SendAlert_var->setUser(username);
        SendAlert_var->setSignature(18);
        SendAlert_var->send();
        delete SendAlert_var;
    }
}

