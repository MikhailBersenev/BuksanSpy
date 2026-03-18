#include "EventEngine/events/securityEvents/CUserRegisterEvent.h"
#include "Loggerd.h"

CUserRegisterEvent::CUserRegisterEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserRegister;
    LOG_TRACE_MSG("CUserRegisterEvent constructed");
}
