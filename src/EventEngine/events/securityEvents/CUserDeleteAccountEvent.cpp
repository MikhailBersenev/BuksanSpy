#include "EventEngine/events/securityEvents/CUserDeleteAccountEvent.h"
#include "Loggerd.h"

CUserDeleteAccountEvent::CUserDeleteAccountEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserDeleteAccount;
    LOG_TRACE_MSG("CUserDeleteAccountEvent constructed");
}
