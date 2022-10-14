#include "StaminaEvent.h"

StaminaEvent::StaminaEvent(int value) : value(value) {}

StaminaEvent::~StaminaEvent() {}

void StaminaEvent::interact(Player &player) { player.changeHealth(value); }

Event *StaminaEvent::clone() const
{
    return new StaminaEvent(*this);
}