#ifndef CUSERAUTHEVENT_H
#define CUSERAUTHEVENT_H


#include "CSecurityEvent.h"

class CUserAuthEvent : public CSecurityEvent
{
public:
    explicit CUserAuthEvent(QObject *parent = nullptr);
};
#endif // CUSERAUTHEVENT_H
