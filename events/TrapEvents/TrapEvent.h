#pragma once
#include "../Event.h"

class TrapEvent : public Event
{
private:
    uint damage;

public:
    explicit TrapEvent(uint damage = 0);
    void interact(Player&) override;
    //virtual void interact(Field& field) override;
};
