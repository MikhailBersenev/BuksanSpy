#ifndef CUSERCHANGEUSERNAMEEVENT_H
#define CUSERCHANGEUSERNAMEEVENT_H

#include "CSecurityEvent.h"

class CUserChangeUserNameEvent : public CSecurityEvent
{
public:
    explicit CUserChangeUserNameEvent(QObject *parent = nullptr);
};
#endif // CUSERCHANGEUSERNAMEEVENT_H
