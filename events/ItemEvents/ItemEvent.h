#pragma once

#include "../Event.h"
#include "../../models/Player.h"

class ItemEvent : public Event {
public:
    ItemEvent() = default;

    ItemEvent(const ItemEvent &obj);

    virtual ~ItemEvent() = 0;
};
