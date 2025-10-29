#include "CShiftOpeningEvent.h"

CShiftOpeningEvent::CShiftOpeningEvent(QObject *parent)
    : CSalesEvent{parent}
{
    m_nSignature = nSignature::ShiftOpening;
}
