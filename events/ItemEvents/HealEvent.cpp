#include "HealEvent.h"

HealEvent::HealEvent(int value) : value(value) {}

HealEvent::~HealEvent() {}

void HealEvent::interact(Player &player) { player.changeHealth(value); }

Event *HealEvent::clone() const
{
    return new HealEvent(*this);
}