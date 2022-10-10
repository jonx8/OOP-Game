#pragma once
typedef unsigned int uint;
class Event;
class EventBuilder
{
public:
    virtual Event *create() const = 0;
    virtual void reset() = 0;
    virtual ~EventBuilder() = 0;
};