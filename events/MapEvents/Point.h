#pragma once
struct Point
{
    Point() = default;
    Point(uint x, uint y) : x(x), y(y) {}
    uint x;
    uint y;
};