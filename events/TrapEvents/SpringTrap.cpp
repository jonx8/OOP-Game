#include "SpringTrap.h"
#include "../../models/Field.h"

SpringTrap::SpringTrap(uint pushDist, uint damage) : TrapEvent::TrapEvent(damage), pushDist(pushDist) {}
SpringTrap::~SpringTrap() {}
void SpringTrap::interact(Field &field)
{
    int direction = rand() % 4; // direction of the push
    for (size_t i = 0; i < pushDist; i++)
    {
        field.movePlayer(static_cast<Field::directions>(direction));
    }
    field.eventCheck();
}