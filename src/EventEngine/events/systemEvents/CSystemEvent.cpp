#include "EventEngine/events/systemEvents/CSystemEvent.h"

CSystemEvent::CSystemEvent(QObject *parent)
    : CEvent{parent}
{
    m_nSignatureType = nSignatureType::System;
}
