#pragma once
#include "TrapEvent.h"
#include "../../models/Field.h"

class SpringTrap : public TrapEvent
{
private:
    uint pushDist;

public:
    SpringTrap(uint pushDist, uint damage);
    ~SpringTrap();
    void interact(Field &field) override;
};
