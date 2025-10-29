#ifndef CSECURITYEVENT_H
#define CSECURITYEVENT_H

#include "../CEvent.h"
class CSecurityEvent : public CEvent
{
public:
    explicit CSecurityEvent(QObject *parent = nullptr);
};
#endif // CSECURITYEVENT_H
