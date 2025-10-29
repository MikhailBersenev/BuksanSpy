#ifndef CSHIFTCLOSINGEVENT_H
#define CSHIFTCLOSINGEVENT_H


#include "CSalesEvent.h"

class CShiftClosingEvent : public CSalesEvent
{
public:
    explicit CShiftClosingEvent(QObject *parent = nullptr);
};
#endif // CSHIFTCLOSINGEVENT_H
