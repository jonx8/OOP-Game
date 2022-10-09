#include "SpringTrap.h"

SpringTrap::SpringTrap(uint pushDist, uint damage) : TrapEvent::TrapEvent(damage), pushDist(pushDist) {}

void SpringTrap::interact(Player &player)
{
    player.changeHealth(-damage);
}
