#include "CShiftClosingEvent.h"
#include "Loggerd.h"

CShiftClosingEvent::CShiftClosingEvent(QObject *parent)
    : CSalesEvent{parent}
{
    m_nSignature = nSignature::ShiftClosing;
    LOG_TRACE_MSG("CShiftClosingEvent constructed");
}
