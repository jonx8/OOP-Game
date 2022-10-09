#pragma once
#include "TrapEvent.h"

class StakesTrap : public TrapEvent
{
public:
    StakesTrap(uint damage);
    ~StakesTrap();
    void interact(Field& field) override; 
};
