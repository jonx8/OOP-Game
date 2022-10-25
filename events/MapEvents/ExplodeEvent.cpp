#include "ExplodeEvent.h"
#include "../../eventsRegister/EventsRegister.h"

ExplodeEvent::ExplodeEvent(uint damage, uint radius, EventsRegister *evReg) : MapEvent::MapEvent(radius), damage(damage), evReg(evReg) {}

ExplodeEvent::ExplodeEvent(const ExplodeEvent& obj) : MapEvent(obj)
{
    damage = obj.damage;
    evReg = obj.evReg;
}

ExplodeEvent::~ExplodeEvent() {}

void ExplodeEvent::pushPlayer(uint distance, Field &field) const
{
    int direction = rand() % 4; // direction of the push
    for (size_t i = 0; i < distance; i++)
    {
        field.movePlayer(static_cast<Field::Directions>(direction));
    }
}

void ExplodeEvent::interact(Player &player, Field &field)
{
    notify(Message("ExplodeEvent was executed"));
    if (player.hasArmor())
    {
        player.setArmor(false);
    }
    else
    {
        player.changeHealth(-damage);
    }
    cellsTraversal(field);
    pushPlayer(radius, field);
}

Event *ExplodeEvent::clone() const
{
    return new ExplodeEvent(*this);
}

void ExplodeEvent::cellsTraversal(Field &field)
{
    Point playerCoords;
    playerCoords.x = field.getPlayerCoords().first;
    playerCoords.y = field.getPlayerCoords().second;
    int h = field.getHeight();
    int w = field.getWidth();
    int y0 = playerCoords.y - radius;
    int x0 = playerCoords.x - radius;
    field.getCell(playerCoords.y, playerCoords.x).setEvent(evReg->getEvent(HEAL_EVENT));
    for (int i = y0; i <= y0 + 2 * static_cast<int>(radius); i++)
    {
        for (int j = x0; j <= x0 + 2 * static_cast<int>(radius); j++)
        {
            if (round(distanceCompute(Point(j, i), playerCoords)) <= radius)
            {
                if (field.getCell((i + h) % h, (j + w) % w).getType() == Cell::Objects::WALL)
                {
                    field.getCell((i + h) % h, (j + w) % w).setType(Cell::Objects::GROUND);
                    field.getCell((i + h) % h, (j + w) % w).setPassable(true);
                }
            }
        }
    }
}