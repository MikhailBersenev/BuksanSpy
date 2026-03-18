#include "EventEngine/events/securityEvents/CUserBanAccountEvent.h"
#include "Loggerd.h"

CUserBanAccountEvent::CUserBanAccountEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserBanAccount;
    LOG_TRACE_MSG("CUserBanAccountEvent constructed");
}
