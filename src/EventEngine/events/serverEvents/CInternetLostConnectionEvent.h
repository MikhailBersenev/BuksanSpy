#ifndef CINTERNETLOSTCONNECTIONEVENT_H
#define CINTERNETLOSTCONNECTIONEVENT_H

#include "CServerEvent.h"

class CInternetLostConnectionEvent : public CServerEvent
{
public:
    explicit CInternetLostConnectionEvent(QObject *parent = nullptr);
};
#endif // CINTERNETLOSTCONNECTIONEVENT_H
