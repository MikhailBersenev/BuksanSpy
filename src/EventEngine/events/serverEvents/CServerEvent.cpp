#include "CServerEvent.h"
#include "Loggerd.h"

CServerEvent::CServerEvent(QObject *parent)
    : CEvent{parent}
{
    m_nSignatureType = nSignatureType::Server;
    LOG_TRACE_MSG("CServerEvent constructed");
}
