#include "ExplodeEvent.h"
#include "../../models/Field.h"
#include "../../models/Player.h"

ExplodeEvent::ExplodeEvent(uint damage, uint radius) : MapEvent::MapEvent(radius), damage(damage) {}

ExplodeEvent::~ExplodeEvent() {}

void ExplodeEvent::pushPlayer(uint distance, Field &field) const
{
    int direction = rand() % 4; // direction of the push
    for (size_t i = 0; i < distance; i++)
    {
        field.movePlayer(static_cast<Field::directions>(direction));
    }
}

void ExplodeEvent::interact(Player &player)
{
    if (player.hasArmor())
    {
        player.setArmor(false);
    }
    else
    {
        player.changeHealth(-damage);
    }
}

void ExplodeEvent::interact(Field &field)
{
    pushPlayer(radius, field);
}