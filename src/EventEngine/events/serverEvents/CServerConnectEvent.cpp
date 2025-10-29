#include "EventEngine/events/serverEvents/CServerConnectEvent.h"

CServerConnectEvent::CServerConnectEvent(QObject *parent)
    : CServerEvent{parent}
{
    m_nSignature = nSignature::ServerConnect;
}
