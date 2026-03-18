#include "EventEngine/events/systemEvents/CSystemEvent.h"
#include "Loggerd.h"

CSystemEvent::CSystemEvent(QObject *parent)
    : CEvent{parent}
{
    m_nSignatureType = nSignatureType::System;
    LOG_TRACE_MSG("CSystemEvent constructed");
}
