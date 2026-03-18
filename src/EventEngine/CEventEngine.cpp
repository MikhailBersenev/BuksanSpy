#include "CEventEngine.h"
#include "CEventSender.h"
#include "Loggerd.h"

bool CEventEngine::fSubscribe(CEventSender *pSender)
{
    if(!pSender)
        return false;
    if(!pSender->fAddEngine(this)) {
        LOG_CRITICAL_MSG("Unable to add event engine to CEventSender");
        return false;
    }
    return true;
}

CEventEngine::CEventEngine(QObject *parent)
    : QObject{parent}
{
    LOG_TRACE_MSG("CEventEngine constructed");
}
