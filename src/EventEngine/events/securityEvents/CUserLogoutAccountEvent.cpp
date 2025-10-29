#include "EventEngine/events/securityEvents/CUserLogoutAccountEvent.h"

CUserLogoutAccountEvent::CUserLogoutAccountEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserLogoutAccount;
}
