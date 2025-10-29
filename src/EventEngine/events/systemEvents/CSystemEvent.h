#ifndef CSYSTEMEVENT_H
#define CSYSTEMEVENT_H

#include "../CEvent.h"
class CSystemEvent : public CEvent
{
public:
    explicit CSystemEvent(QObject *parent = nullptr);
};
#endif // CSYSTEMEVENT_H
