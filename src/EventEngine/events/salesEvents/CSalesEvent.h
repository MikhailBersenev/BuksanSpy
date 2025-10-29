#ifndef CSALESEVENT_H
#define CSALESEVENT_H

#include "../CEvent.h"
class CSalesEvent : public CEvent
{
public:
    explicit CSalesEvent(QObject *parent = nullptr);
};
#endif // CSALESEVENT_H
