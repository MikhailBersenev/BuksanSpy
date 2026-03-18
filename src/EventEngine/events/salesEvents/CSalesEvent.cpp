#include "CSalesEvent.h"
#include "Loggerd.h"

CSalesEvent::CSalesEvent(QObject *parent)
    : CEvent{parent}
{
    m_nSignatureType = nSignatureType::Sales;
    LOG_TRACE_MSG("CSalesEvent constructed");
}
