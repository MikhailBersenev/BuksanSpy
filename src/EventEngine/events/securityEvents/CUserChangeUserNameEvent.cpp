#include "EventEngine/events/securityEvents/CUserChangeUserNameEvent.h"
#include "Loggerd.h"

CUserChangeUserNameEvent::CUserChangeUserNameEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserChangeUserName;
    LOG_TRACE_MSG("CUserChangeUserNameEvent constructed");
}
