#ifndef CEXPORTRECEIPTTOFILEEVENT_H
#define CEXPORTRECEIPTTOFILEEVENT_H


#include "CSalesEvent.h"

class CExportReceiptToFileEvent : public CSalesEvent
{
public:
    explicit CExportReceiptToFileEvent(QObject *parent = nullptr);
};
#endif // CEXPORTRECEIPTTOFILEEVENT_H
