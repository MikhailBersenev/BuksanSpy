#include "EventEngine/events/securityEvents/CUserAuthEvent.h"
#include "Loggerd.h"

CUserAuthEvent::CUserAuthEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserAuth;
    LOG_TRACE_MSG("CUserAuthEvent constructed");
}
