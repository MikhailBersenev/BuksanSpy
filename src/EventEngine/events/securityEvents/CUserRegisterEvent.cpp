#include "EventEngine/events/securityEvents/CUserRegisterEvent.h"

CUserRegisterEvent::CUserRegisterEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserRegister;
}
