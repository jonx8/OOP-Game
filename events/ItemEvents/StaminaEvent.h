#pragma once
#include "ItemEvent.h"

class StaminaEvent : public ItemEvent
{
private:
    int value;

public:
    StaminaEvent(int value);
    StaminaEvent(const StaminaEvent& obj);
    ~StaminaEvent();
    void interact(Player &player, Field& field) override;
    Event *clone() const override;
};
