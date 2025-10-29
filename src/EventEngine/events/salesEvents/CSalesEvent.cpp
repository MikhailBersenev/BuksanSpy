#include "CSalesEvent.h"

CSalesEvent::CSalesEvent(QObject *parent)
    : CEvent{parent}
{
    m_nSignatureType = nSignatureType::Sales;
}
