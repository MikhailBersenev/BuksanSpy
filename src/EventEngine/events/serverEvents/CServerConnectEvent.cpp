#include "EventEngine/events/serverEvents/CServerConnectEvent.h"
#include "Loggerd.h"

CServerConnectEvent::CServerConnectEvent(QObject *parent)
    : CServerEvent{parent}
{
    m_nSignature = nSignature::ServerConnect;
    LOG_TRACE_MSG("CServerConnectEvent constructed");
}
