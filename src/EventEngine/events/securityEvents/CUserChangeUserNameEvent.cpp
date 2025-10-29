#include "EventEngine/events/securityEvents/CUserChangeUserNameEvent.h"

CUserChangeUserNameEvent::CUserChangeUserNameEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserChangeUserName;
}
