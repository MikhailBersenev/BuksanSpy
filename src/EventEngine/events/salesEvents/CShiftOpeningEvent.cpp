#include "CShiftOpeningEvent.h"
#include "Loggerd.h"

CShiftOpeningEvent::CShiftOpeningEvent(QObject *parent)
    : CSalesEvent{parent}
{
    m_nSignature = nSignature::ShiftOpening;
    LOG_TRACE_MSG("CShiftOpeningEvent constructed");
}
