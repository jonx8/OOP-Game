#pragma once
#include "../Event.h"

class TrapEvent : public Event
{
private:
    uint damage;

public:
    explicit TrapEvent(uint damage = 0);
    virtual ~TrapEvent() = 0;
    void interact(Player& player) override;
    void interact(Field& field) override;
};

