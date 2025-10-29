#ifndef CUSERCHANGEPASSWORDEVENT_H
#define CUSERCHANGEPASSWORDEVENT_H

#include "CSecurityEvent.h"

class CUserChangePasswordEvent : public CSecurityEvent
{
public:
    explicit CUserChangePasswordEvent(QObject *parent = nullptr);
};
#endif // CUSERCHANGEPASSWORDEVENT_H
