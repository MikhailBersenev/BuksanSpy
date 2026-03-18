#include "EventEngine/events/securityEvents/CUserUnlockAccountEvent.h"
#include "Loggerd.h"

CUserUnlockAccountEvent::CUserUnlockAccountEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserUnlockAccount;
    LOG_TRACE_MSG("CUserUnlockAccountEvent constructed");
}
