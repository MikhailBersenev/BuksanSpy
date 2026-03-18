#include "EventEngine/events/serverEvents/CInternetLostConnectionEvent.h"
#include "Loggerd.h"

CInternetLostConnectionEvent::CInternetLostConnectionEvent(QObject *parent)
    : CServerEvent{parent}
{
    m_nSignature = nSignature::InternetLostConnection;
    LOG_TRACE_MSG("CInternetLostConnectionEvent constructed");
}
