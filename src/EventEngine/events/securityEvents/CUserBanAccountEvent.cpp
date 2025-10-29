#include "EventEngine/events/securityEvents/CUserBanAccountEvent.h"

CUserBanAccountEvent::CUserBanAccountEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserBanAccount;
}
