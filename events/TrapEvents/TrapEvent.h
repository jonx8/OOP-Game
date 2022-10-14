#pragma once
#include "../Event.h"

class TrapEvent : public Event
{
protected:
    uint damage;

public:
    explicit TrapEvent(uint damage = 0);
    TrapEvent(const TrapEvent &obj);
    virtual ~TrapEvent() = 0;
};
