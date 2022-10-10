#include "TrapEventBuilder.h"
#include <iostream>
#include "../events/TrapEvents/StakesTrap.h"
#include "../events/TrapEvents/SpringTrap.h"

TrapEventBuilder::TrapEventBuilder(uint damage) : damage(damage), pushDist(0), event(nullptr) {}
TrapEventBuilder::~TrapEventBuilder() {}

void TrapEventBuilder::buildStakes()
{
    reset();
    event = new StakesTrap(damage);
    std::cout << event << std::endl;
}

void TrapEventBuilder::buildSpring(uint pushDist)
{
    reset();
   // event = new SpringTrap(pushDist, damage);
}

Event *TrapEventBuilder::create() const
{
    return event;
}

void TrapEventBuilder::setDamage(uint damage) { this->damage = damage; }
void TrapEventBuilder::setPushDist(uint pushDist) { this->pushDist = pushDist; }
void TrapEventBuilder::reset()
{
    if (event)
    {
        delete event;
    };
};