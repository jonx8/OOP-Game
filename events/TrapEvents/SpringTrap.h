#pragma once
#include "TrapEvent.h"

class SpringTrap : public TrapEvent
{
private:
    uint pushDist;

public:
    SpringTrap(uint pushDist, uint damage);
    ~SpringTrap();
    void setDistance();
    void interact(Player &player, Field &field) override;
    Event *clone() const override;
};
