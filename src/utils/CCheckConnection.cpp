#include "CCheckConnection.h"
#include "CEventHelper.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QTimer>
#include <QDebug>

CCheckConnection::CCheckConnection(QObject *parent) : QTimer(parent),
    m_pEventHelper(nullptr),
    m_nPreviousState(0)
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
    // Инициализация EventHelper при первой проверке
    if (!m_pEventHelper) {
        m_pEventHelper = new CEventHelper(this);
    }
    
    if(reply->bytesAvailable()==0 && reply->bytesAvailable() != m_nPreviousState)
    {//Проверка соединения с Интернетом - потеря соединения
        m_pEventHelper->fSendInternetLostConnectionEvent(m_strUsername);
        m_nPreviousState = reply->bytesAvailable();
    }
    else
    {
        if(reply->bytesAvailable()>0 && reply->bytesAvailable() != m_nPreviousState)
        {
            // Восстановление соединения
            m_pEventHelper->fSendInternetConnectionRecoveredEvent(m_strUsername);
            m_nPreviousState = reply->bytesAvailable();
        }
    }
}

