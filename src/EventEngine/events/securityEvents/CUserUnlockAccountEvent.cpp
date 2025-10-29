#include "EventEngine/events/securityEvents/CUserUnlockAccountEvent.h"

CUserUnlockAccountEvent::CUserUnlockAccountEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserUnlockAccount;
}
