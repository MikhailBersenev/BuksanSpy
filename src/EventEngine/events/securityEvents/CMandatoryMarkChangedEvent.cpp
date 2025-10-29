#include "EventEngine/events/securityEvents/CMandatoryMarkChangedEvent.h"

CMandatoryMarkChangedEvent::CMandatoryMarkChangedEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::MandatoryMarkChanged;
}
