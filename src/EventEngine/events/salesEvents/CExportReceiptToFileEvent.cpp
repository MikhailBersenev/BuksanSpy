#include "CExportReceiptToFileEvent.h"

CExportReceiptToFileEvent::CExportReceiptToFileEvent(QObject *parent)
    : CSalesEvent{parent}
{
    m_nSignature = nSignature::ExportReceiptToFile;
}
