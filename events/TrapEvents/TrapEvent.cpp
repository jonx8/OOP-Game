#include "TrapEvent.h"

TrapEvent::TrapEvent(uint damage): damage(damage) {}

void TrapEvent::interact(Player &player)
{
    player.changeHealth(-damage);
}
