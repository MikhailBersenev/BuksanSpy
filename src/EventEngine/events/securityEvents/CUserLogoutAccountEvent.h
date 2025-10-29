#ifndef CUSERLOGOUTACCOUNTEVENT_H
#define CUSERLOGOUTACCOUNTEVENT_H

#include "CSecurityEvent.h"

class CUserLogoutAccountEvent : public CSecurityEvent
{
public:
    explicit CUserLogoutAccountEvent(QObject *parent = nullptr);
};
#endif // CUSERLOGOUTACCOUNTEVENT_H
