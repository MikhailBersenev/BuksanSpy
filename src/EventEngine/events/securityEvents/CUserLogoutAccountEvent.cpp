#include "EventEngine/events/securityEvents/CUserLogoutAccountEvent.h"
#include "Loggerd.h"

CUserLogoutAccountEvent::CUserLogoutAccountEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserLogoutAccount;
    LOG_TRACE_MSG("CUserLogoutAccountEvent constructed");
}
