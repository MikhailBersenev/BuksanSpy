#include "EventEngine/events/securityEvents/CUserChangePasswordEvent.h"
#include "Loggerd.h"

CUserChangePasswordEvent::CUserChangePasswordEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserChangePassword;
    LOG_TRACE_MSG("CUserChangePasswordEvent constructed");
}
