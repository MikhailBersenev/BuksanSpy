#include "CServerEvent.h"

CServerEvent::CServerEvent(QObject *parent)
    : CEvent{parent}
{
    m_nSignatureType = nSignatureType::Server;
}
