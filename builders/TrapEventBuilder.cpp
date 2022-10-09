#include "TrapEventBuilder.h"


TrapEventBuilder::TrapEventBuilder(uint damage) : damage(damage) {}
TrapEventBuilder::~TrapEventBuilder() {}

Event *TrapEventBuilder::create() const
{
    return new StakesTrap(damage);
}

void TrapEventBuilder::setDamage(uint damage) { this->damage = damage; }