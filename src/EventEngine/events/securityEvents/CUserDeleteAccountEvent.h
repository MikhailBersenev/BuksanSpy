#ifndef CUSERDELETEACCOUNTEVENT_H
#define CUSERDELETEACCOUNTEVENT_H


#include "CSecurityEvent.h"

class CUserDeleteAccountEvent : public CSecurityEvent
{
public:
    explicit CUserDeleteAccountEvent(QObject *parent = nullptr);
};
#endif // CUSERDELETEACCOUNTEVENT_H
