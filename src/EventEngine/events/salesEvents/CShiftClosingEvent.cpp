#include "CShiftClosingEvent.h"

CShiftClosingEvent::CShiftClosingEvent(QObject *parent)
    : CSalesEvent{parent}
{
    m_nSignature = nSignature::ShiftClosing;
}
