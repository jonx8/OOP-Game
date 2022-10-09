#pragma once
#include "../events/Event.h"

class EventBuilder
{
public:
    virtual Event* create() const = 0;
    virtual ~EventBuilder() = 0;
};