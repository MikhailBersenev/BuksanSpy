#include "CCheckConnection.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>
#include <QDebug>
#include "CSendAlert.h"
CCheckConnection::CCheckConnection(QObject *parent) : QTimer(parent)
{

    connect(this, SIGNAL(timeout()), this, SLOT(CheckInternet()));
    setInterval(30000);

}



void CCheckConnection::fCheckInternet()
{
    QNetworkAccessManager nam;
    QNetworkRequest req(QUrl("http://networkcheck.kde.org/"));
    QNetworkReply *reply =  nam.get(req);
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    if(reply->bytesAvailable()==0 && reply->bytesAvailable() != m_nPreviousState)
    {//Проверка соединения с Интернетом

        CSendAlert *SendAlert_var = new CSendAlert(this);
        SendAlert_var->fPrepare();
        SendAlert_var->fSetUser(m_strUsername);
        SendAlert_var->fSetSignature(13);
        SendAlert_var->fSend();
        m_nPreviousState = reply->bytesAvailable();
        delete SendAlert_var;
    }
    else
    {
        if(reply->bytesAvailable()>0 && reply->bytesAvailable() != m_nPreviousState)
        {
        m_pSendAlert = new CSendAlert(this);
        m_pSendAlert->fPrepare();
        m_pSendAlert->fSetUser(m_strUsername);
        m_pSendAlert->fSetSignature(14);
        m_pSendAlert->fSend();
        m_nPreviousState = reply->bytesAvailable();
        delete m_pSendAlert;
        }
    }
}

