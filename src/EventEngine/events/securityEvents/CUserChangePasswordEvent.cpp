#include "EventEngine/events/securityEvents/CUserChangePasswordEvent.h"

CUserChangePasswordEvent::CUserChangePasswordEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserChangePassword;
}
