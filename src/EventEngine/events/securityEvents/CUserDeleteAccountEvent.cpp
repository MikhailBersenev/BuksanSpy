#include "EventEngine/events/securityEvents/CUserDeleteAccountEvent.h"

CUserDeleteAccountEvent::CUserDeleteAccountEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserDeleteAccount;
}
