#include "FloodEvent.h"


FloodEvent::FloodEvent(uint radius) : MapEvent::MapEvent(radius) {}
FloodEvent::~FloodEvent() {}

void FloodEvent::cellsTraversal(Field &field)
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
                field.getCell((i + h) % h, (j + w) % w).setType(Cell::Objects::WATER);
                field.getCell((i + h) % h, (j + w) % w).setPassable(true);
            }
        }
    }
}

void FloodEvent::interact(Player &player)
{
    player.changeStamina(-25);
}

void FloodEvent::interact(Field &field)
{
    cellsTraversal(field);
    field.getCell(field.getHeight() * 0.75, field.getWidth() * 0.8).setEvent(field.eventGenerate(EXPLODE_EVENT));

}


Event *FloodEvent::clone() const
{
    return new FloodEvent(*this);
}