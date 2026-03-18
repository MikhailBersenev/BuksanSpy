#include "CEventSender.h"
#include "Loggerd.h"
#include <QString>
CEventSender::CEventSender(QObject *parent)
    : QObject{parent}
{
    m_vEngines = new QList<CEventEngine*>;
    LOG_TRACE_MSG("CEventSender constructed");
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
    LOG_INFO_MSG((QStringLiteral("Event engine registered: ") + pEngine->fGetNameString()).toStdString());
    return true;
}
