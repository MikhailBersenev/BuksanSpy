#include "CSecurityEvent.h"
#include "Loggerd.h"

CSecurityEvent::CSecurityEvent(QObject *parent)
    : CEvent{parent}
{
    m_nSignatureType = nSignatureType::Security;
    LOG_TRACE_MSG("CSecurityEvent constructed");
}
