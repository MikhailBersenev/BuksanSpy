#ifndef CUSERUNLOCKACCOUNTEVENT_H
#define CUSERUNLOCKACCOUNTEVENT_H

#include "CSecurityEvent.h"

class CUserUnlockAccountEvent : public CSecurityEvent
{
public:
    explicit CUserUnlockAccountEvent(QObject *parent = nullptr);
};
#endif // CUSERUNLOCKACCOUNTEVENT_H
