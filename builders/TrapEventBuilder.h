#pragma once
#include "EventBuilder.h"
#include "../events/TrapEvents/StakesTrap.h"
//#include "../events/TrapEvents/SpringTrap.h"

class TrapEventBuilder : public EventBuilder
{
private:
    uint damage;
    uint pushDist;
    Event *event;

public:
    explicit TrapEventBuilder(uint damage);
    ~TrapEventBuilder();
    void reset() override;
    void buildStakes();
    void buildSpring(uint pushDist);
    void setDamage(uint damage);
    void setPushDist(uint pushDist);
    Event *create() const override;
};
