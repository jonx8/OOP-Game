#include "MapEvent.h"
MapEvent::MapEvent(uint radius) : radius(radius) {}
MapEvent::~MapEvent() {}

double MapEvent::distanceCompute(Point p1, Point p2) const
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

void MapEvent::interact(Player &player) {}
void MapEvent::interact(Field &field) {}
