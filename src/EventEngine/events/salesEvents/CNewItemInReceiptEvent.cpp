#include "CNewItemInReceiptEvent.h"

CNewItemInReceiptEvent::CNewItemInReceiptEvent(QObject *parent)
    : CSalesEvent{parent}
{
    m_nSignature = nSignature::NewItemInReceipt;
}
