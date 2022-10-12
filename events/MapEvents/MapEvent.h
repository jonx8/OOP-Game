#pragma once
#include "../Event.h"
#include "Point.h"

class MapEvent : public Event
{
protected:
    uint radius;

    MapEvent(uint radius);
    uint distanceCompute(Point p1, Point p2) const;
    uint isqrt(uint num) const;

public:
    virtual ~MapEvent() = 0;
    virtual void interact(Field &field) = 0;
    virtual void interact(Player &player) = 0;
};
