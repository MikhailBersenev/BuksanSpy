#include "EventEngine/events/serverEvents/CInternetConnectionRecoveredEvent.h"
#include "Loggerd.h"

CInternetConnectionRecoveredEvent::CInternetConnectionRecoveredEvent(QObject *parent)
    : CServerEvent{parent}
{
    m_nSignature = nSignature::InternetConnectionRecovered;
    LOG_TRACE_MSG("CInternetConnectionRecoveredEvent constructed");
}
