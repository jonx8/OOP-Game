#pragma once
#include "TrapEvent.h"

class StakesTrap : public TrapEvent
{
public:
    using TrapEvent::TrapEvent;
    ~StakesTrap() override = default;
    void interact(Player& player, Field& field) override;
    [[nodiscard]] Event* clone() const override;
};
