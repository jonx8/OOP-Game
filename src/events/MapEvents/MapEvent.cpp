#include "MapEvent.h"

MapEvent::MapEvent(int radius) : radius(radius) {}

MapEvent::MapEvent(const MapEvent &obj) : MapEvent(obj.radius) {
    observers_list = obj.observers_list;
}

MapEvent::~MapEvent() = default;

double MapEvent::distanceCompute(Point p1, Point p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}
