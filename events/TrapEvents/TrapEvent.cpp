#include "TrapEvent.h"
#include "../../models/Player.h"

TrapEvent::TrapEvent(uint damage): damage(damage) {}

void TrapEvent::interact(Player &player)
{
    player.changeHealth(-damage);
}