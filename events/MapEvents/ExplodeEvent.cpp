#include "ExplodeEvent.h"
#include "../../models/Field.h"
#include "../../models/Player.h"
#include "../../models/Cell.h"

ExplodeEvent::ExplodeEvent(uint damage, uint radius) : MapEvent::MapEvent(radius), damage(damage) {}

ExplodeEvent::~ExplodeEvent() {}

void ExplodeEvent::pushPlayer(uint distance, Field &field) const
{
    int direction = rand() % 4; // direction of the push
    for (size_t i = 0; i < distance; i++)
    {
        field.movePlayer(static_cast<Field::Directions>(direction));
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
    for (int i = y0; i <= y0 + 2 * static_cast<int>(radius); i++)
    {
        for (int j = x0; j <= x0 + 2 * static_cast<int>(radius); j++)
        {
            if (round(distanceCompute(Point(j, i), playerCoords)) <= radius)
            {
                field.getCell((i + h) % h, (j + w) % w).setPassable(true);
            }
            std::cout << i << ' ' << j << '\n';
        }
    }
}