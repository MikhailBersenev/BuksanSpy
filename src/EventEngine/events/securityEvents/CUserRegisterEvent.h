#ifndef CUSERREGISTEREVENT_H
#define CUSERREGISTEREVENT_H

#include "CSecurityEvent.h"

class CUserRegisterEvent : public CSecurityEvent
{
public:
    explicit CUserRegisterEvent(QObject *parent = nullptr);
};
#endif // CUSERREGISTEREVENT_H
