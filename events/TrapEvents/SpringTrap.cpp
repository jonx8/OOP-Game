#include "SpringTrap.h"
#include "../../models/Field.h"

SpringTrap::SpringTrap(uint pushDist, uint damage) : TrapEvent::TrapEvent(damage), pushDist(pushDist) {}
SpringTrap::~SpringTrap() {}
void SpringTrap::interact(Field &field)
{
    for (size_t i = 0; i < pushDist; i++)
    {
        field.movePlayer(Field::UP);
    }
}