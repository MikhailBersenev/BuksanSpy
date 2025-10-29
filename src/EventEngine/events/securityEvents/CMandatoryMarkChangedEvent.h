#ifndef CMANDATORYMARKCHANGEDEVENT_H
#define CMANDATORYMARKCHANGEDEVENT_H

#include "CSecurityEvent.h"

class CMandatoryMarkChangedEvent : public CSecurityEvent
{
public:
    explicit CMandatoryMarkChangedEvent(QObject *parent = nullptr);
};
#endif // CMANDATORYMARKCHANGEDEVENT_H
