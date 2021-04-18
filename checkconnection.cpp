#include "checkconnection.h"
#include <QNetworkConfigurationManager>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>
#include <QDebug>
#include "sendalert.h"
CheckConnection::CheckConnection(QObject *parent) : QTimer(parent)
{

    connect(this, SIGNAL(timeout()), this, SLOT(CheckInternet()));
    setInterval(30000);

}



void CheckConnection::CheckInternet()
{
    QNetworkAccessManager nam;
    QNetworkRequest req(QUrl("http://networkcheck.kde.org/"));
    QNetworkReply *reply =  nam.get(req);
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    if(reply->bytesAvailable()==0 && reply->bytesAvailable() != previousstate)
    {//Проверка соединения с Интернетом

        SendAlert *SendAlert_var = new SendAlert(this);
        SendAlert_var->prepare();
        SendAlert_var->setUser(username);
        SendAlert_var->setSignature(17);
        SendAlert_var->send();
        previousstate = reply->bytesAvailable();
        delete SendAlert_var;
    }
    else
    {
        if(reply->bytesAvailable()>0 && reply->bytesAvailable() != previousstate)
        {
        SendAlert_var = new SendAlert(this);
        SendAlert_var->prepare();
        SendAlert_var->setUser(username);
        SendAlert_var->setSignature(18);
        SendAlert_var->send();
        previousstate = reply->bytesAvailable();
        delete SendAlert_var;
        }
    }
}

