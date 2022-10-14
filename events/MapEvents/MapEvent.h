#pragma once
#include <cmath>
#include "../Event.h"
#include "Point.h"

class MapEvent : public Event
{
protected:
    uint radius;
    explicit MapEvent(uint radius);
    virtual void cellsTraversal(Field &field) = 0;
    double distanceCompute(Point p1, Point p2) const;

public:
    virtual ~MapEvent() = 0;
};
