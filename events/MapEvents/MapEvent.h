#pragma once
#include <cmath>
#include "../Event.h"
#include "Point.h"


class MapEvent : public Event
{
protected:
    uint radius;
    MapEvent(uint radius);
    double distanceCompute(Point p1, Point p2) const;
    virtual void cellsTraversal(Field& field) = 0;
public:
    virtual ~MapEvent() = 0;
    void interact(Player &player) override;
    void interact(Field &field) override;

};
