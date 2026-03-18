#include "EventEngine/events/securityEvents/CMandatoryMarkChangedEvent.h"
#include "Loggerd.h"

CMandatoryMarkChangedEvent::CMandatoryMarkChangedEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::MandatoryMarkChanged;
    LOG_TRACE_MSG("CMandatoryMarkChangedEvent constructed");
}
