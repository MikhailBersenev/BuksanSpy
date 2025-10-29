#ifndef CINTERNETCONNECTIONRECOVEREDEVENT_H
#define CINTERNETCONNECTIONRECOVEREDEVENT_H

#include "CServerEvent.h"

class CInternetConnectionRecoveredEvent : public CServerEvent
{
public:
    explicit CInternetConnectionRecoveredEvent(QObject *parent = nullptr);
};
#endif // CINTERNETCONNECTIONRECOVEREDEVENT_H
