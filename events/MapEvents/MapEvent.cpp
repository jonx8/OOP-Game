#include "MapEvent.h"
MapEvent::MapEvent(uint radius) : radius(radius) {}
MapEvent::~MapEvent() {}

uint MapEvent::distanceCompute(Point p1, Point p2) const
{
    return isqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) + (p1.y - p2.y));
}

uint MapEvent::isqrt(uint num) const
{
    uint root = (num / 0x3f + 0x3f) >> 1;
    root = (num / root + root) >> 1;
    root = (num / root + root) >> 1;
    return root;
}