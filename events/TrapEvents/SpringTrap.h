#pragma once
#include "TrapEvent.h"

class SpringTrap : public TrapEvent
{
private:
    uint pushDist;

public:
    SpringTrap(uint pushDist, uint damage);
    SpringTrap(const SpringTrap &obj);
    ~SpringTrap();
    void setDistance();
    void interact(Field &field) override;
    void interact(Player &player) override;
    Event *clone() const override;
};
