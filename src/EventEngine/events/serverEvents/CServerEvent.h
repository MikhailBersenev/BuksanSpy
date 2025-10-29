#ifndef CSERVEREVENT_H
#define CSERVEREVENT_H

#include "../CEvent.h"
class CServerEvent : public CEvent
{
public:
    explicit CServerEvent(QObject *parent = nullptr);
};
#endif // CSERVEREVENT_H
