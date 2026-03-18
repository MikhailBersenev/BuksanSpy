#include "CNewItemInReceiptEvent.h"
#include "Loggerd.h"

CNewItemInReceiptEvent::CNewItemInReceiptEvent(QObject *parent)
    : CSalesEvent{parent}
{
    m_nSignature = nSignature::NewItemInReceipt;
    LOG_TRACE_MSG("CNewItemInReceiptEvent constructed");
}
