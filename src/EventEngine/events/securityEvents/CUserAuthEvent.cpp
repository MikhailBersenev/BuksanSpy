#include "EventEngine/events/securityEvents/CUserAuthEvent.h"

CUserAuthEvent::CUserAuthEvent(QObject *parent)
    : CSecurityEvent{parent}
{
    m_nSignature = nSignature::UserAuth;
}
