#ifndef CUSERBANACCOUNTEVENT_H
#define CUSERBANACCOUNTEVENT_H


#include "CSecurityEvent.h"

class CUserBanAccountEvent : public CSecurityEvent
{
public:
    explicit CUserBanAccountEvent(QObject *parent = nullptr);
};
#endif // CUSERBANACCOUNTEVENT_H
