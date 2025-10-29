#include "CSecurityEvent.h"

CSecurityEvent::CSecurityEvent(QObject *parent)
    : CEvent{parent}
{
    m_nSignatureType = nSignatureType::Security;
}
