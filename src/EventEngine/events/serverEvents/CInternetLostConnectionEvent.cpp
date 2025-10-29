#include "EventEngine/events/serverEvents/CInternetLostConnectionEvent.h"

CInternetLostConnectionEvent::CInternetLostConnectionEvent(QObject *parent)
    : CServerEvent{parent}
{
    m_nSignature = nSignature::InternetLostConnection;
}
