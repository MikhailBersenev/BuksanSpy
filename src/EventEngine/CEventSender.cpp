#include "CEventSender.h"
#include <QDebug>
CEventSender::CEventSender(QObject *parent)
    : QObject{parent}
{
    m_vEngines = new QList<CEventEngine*>;
}

CEventSender::~CEventSender()
{
    if(m_vEngines) delete m_vEngines;
}

bool CEventSender::fSendEvent(CEvent *pEvent)
{
    bool bRes = false;
    foreach(CEventEngine* pEventEngine, *m_vEngines) {
        bRes = pEventEngine->fSend(pEvent);
    }

    return bRes;
}

bool CEventSender::fAddEngine(CEventEngine *pEngine)
{
    if(!pEngine)
        return false;
    m_vEngines->append(pEngine);
    qDebug() << pEngine->fGetNameString() << "successfully addded";
    return true;
}
