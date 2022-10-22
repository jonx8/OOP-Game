#include "HealEvent.h"

HealEvent::HealEvent(int value) : value(value) {}

HealEvent::~HealEvent() {}

void HealEvent::interact(Player &player, Field& field) { player.changeHealth(value); }

Event *HealEvent::clone() const
{
    return new HealEvent(*this);
}