#pragma once
#include "ItemEvent.h"

class StaminaEvent : public ItemEvent
{
private:
    int value;

public:
    StaminaEvent(int value);
    ~StaminaEvent();
    void interact(Player &player, Field& field) override;
    Event *clone() const override;
};
