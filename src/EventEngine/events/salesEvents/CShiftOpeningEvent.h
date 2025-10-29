#ifndef CSHIFTOPENINGEVENT_H
#define CSHIFTOPENINGEVENT_H


#include "CSalesEvent.h"

class CShiftOpeningEvent : public CSalesEvent
{
public:
    explicit CShiftOpeningEvent(QObject *parent = nullptr);
};
#endif // CSHIFTOPENINGEVENT_H
