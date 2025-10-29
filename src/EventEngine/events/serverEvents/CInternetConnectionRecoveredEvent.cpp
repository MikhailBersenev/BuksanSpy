#include "EventEngine/events/serverEvents/CInternetConnectionRecoveredEvent.h"

CInternetConnectionRecoveredEvent::CInternetConnectionRecoveredEvent(QObject *parent)
    : CServerEvent{parent}
{
    m_nSignature = nSignature::InternetConnectionRecovered;
}
