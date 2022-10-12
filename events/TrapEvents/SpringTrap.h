#pragma once
#include "TrapEvent.h"

class SpringTrap : public TrapEvent
{
private:
    uint pushDist;

public:
    SpringTrap(uint pushDist, uint damage);
    ~SpringTrap();
    void interact(Field &field) override;
};
