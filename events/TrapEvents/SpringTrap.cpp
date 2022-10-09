#include "SpringTrap.h"

SpringTrap::SpringTrap(uint pushDist, uint damage) : pushDist(pushDist), TrapEvent::TrapEvent(damage) {}

void SpringTrap::interact(Field &field)
{
    for (size_t i = 0; i < pushDist; i++)
    {
        field.movePlayer(Field::UP);
    }
}