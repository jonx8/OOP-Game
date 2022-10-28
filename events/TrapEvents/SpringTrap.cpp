#include "SpringTrap.h"
#include "../../models/Player.h"
#include "../../models/Field.h"

SpringTrap::SpringTrap(uint pushDist, uint damage) : TrapEvent::TrapEvent(damage), pushDist(pushDist) {}
SpringTrap::SpringTrap(const SpringTrap& obj) : TrapEvent::TrapEvent(obj)
{
    pushDist = obj.pushDist;
}

SpringTrap::~SpringTrap() {}

void SpringTrap::interact(Player &player, Field &field)
{
    notify(Message("SpringTrap executed", Message::INFO));
    player.changeHealth(-damage);

    int direction = rand() % 4; // direction of the push
    for (size_t i = 0; i < pushDist; i++)
    {
        field.movePlayer(static_cast<Field::Directions>(direction));
    }
    field.eventCheck();
}

Event *SpringTrap::clone() const
{
    return new SpringTrap(*this);
}