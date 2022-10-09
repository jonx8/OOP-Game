#pragma once
#include "EventBuilder.h"
#include "../events/TrapEvents/StakesTrap.h"
#include "../events/TrapEvents/SpringTrap.h"


class TrapEventBuilder : public EventBuilder
{
private:
    uint damage;
    
public:
    explicit TrapEventBuilder(uint damage = 0);
    ~TrapEventBuilder();
    
    virtual Event *create() const override;
    void setDamage(uint damage);
};
