#ifndef CSERVERCONNECTEVENT_H
#define CSERVERCONNECTEVENT_H


#include "CServerEvent.h"

class CServerConnectEvent : public CServerEvent
{
public:
    explicit CServerConnectEvent(QObject *parent = nullptr);
};
#endif // CSERVERCONNECTEVENT_H
