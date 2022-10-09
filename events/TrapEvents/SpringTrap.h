#pragma once
#include "TrapEvent.h"
class SpringTrap : public TrapEvent
{
private:
    uint pushDist;
    uint damage;
public:
    explicit SpringTrap(uint pushDist, uint damage = 0);
    ~SpringTrap();
    void interact(Player &player) override;
};
