#pragma once
#include "ItemEvent.h"

class HealEvent : public ItemEvent
{
private:
    int value;

public:
    explicit HealEvent(int value);
    HealEvent(const HealEvent& obj);
    ~HealEvent() override = default;
    void interact(Player &player, Field& field) override;
    [[nodiscard]] Event *clone() const override;
};
