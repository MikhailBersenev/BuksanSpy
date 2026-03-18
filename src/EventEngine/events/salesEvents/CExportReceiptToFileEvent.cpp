#include "CExportReceiptToFileEvent.h"
#include "Loggerd.h"

CExportReceiptToFileEvent::CExportReceiptToFileEvent(QObject *parent)
    : CSalesEvent{parent}
{
    m_nSignature = nSignature::ExportReceiptToFile;
    LOG_TRACE_MSG("CExportReceiptToFileEvent constructed");
}
