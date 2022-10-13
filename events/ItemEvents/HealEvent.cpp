#include "HealEvent.h"

HealEvent::HealEvent(int value) : value(value) {}

HealEvent::~HealEvent() {}

void HealEvent::interact(Player &player) { player.changeHealth(value); }
