#pragma once
#include "../Event.h"

class TrapEvent : public Event
{
private:
    uint damage;

public:
    explicit TrapEvent(uint damage = 0);
    ~TrapEvent();
    void interact(Player& player) override;
    virtual void interact(Field& field) = 0;
};
