#pragma once
#include "../Event.h"
#include "../../models/Player.h"

class ItemEvent : public Event
{
public:
    virtual ~ItemEvent() = 0;
    void interact(Player &player) override;
    void interact(Field &field) override;
};
