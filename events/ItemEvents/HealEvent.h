#pragma once
#include "ItemEvent.h"

class HealEvent : public ItemEvent
{
private:
    int value;

public:
    HealEvent(int value);
    ~HealEvent();
    void interact(Player &player) override;
    Event *clone() const override;
};
