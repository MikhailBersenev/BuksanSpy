#include "CEventEngine.h"
#include "CEventSender.h"
#include <QDebug>

bool CEventEngine::fSubscribe(CEventSender *pSender)
{
    if(!pSender)
        return false;
    if(!pSender->fAddEngine(this)) {
        qDebug() << "Unable to add Event engine";
        return false;
    }
    return true;
}

CEventEngine::CEventEngine(QObject *parent)
    : QObject{parent}
{}
