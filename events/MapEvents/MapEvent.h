#pragma once
#include <cmath>
#include "../Event.h"
#include "../../models/Field.h"
#include "../../models/Player.h"
#include "../../models/Cell.h"
#include "Point.h"

class MapEvent : public Event
{
protected:
    uint radius;
    explicit MapEvent(uint radius = 0);
    MapEvent(const MapEvent& obj);
    virtual void cellsTraversal(Field &field) = 0;
    double distanceCompute(Point p1, Point p2) const;

public:
    virtual ~MapEvent() = 0;
};
