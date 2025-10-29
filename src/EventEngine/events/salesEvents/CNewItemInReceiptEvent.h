#ifndef CNEWITEMINRECEIPTEVENT_H
#define CNEWITEMINRECEIPTEVENT_H


#include "CSalesEvent.h"

class CNewItemInReceiptEvent : public CSalesEvent
{
public:
    explicit CNewItemInReceiptEvent(QObject *parent = nullptr);
};
#endif // CNEWITEMINRECEIPTEVENT_H
