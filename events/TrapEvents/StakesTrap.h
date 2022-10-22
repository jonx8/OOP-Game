#pragma once
#include "TrapEvent.h"

class StakesTrap : public TrapEvent
{
public:
    using TrapEvent::TrapEvent;
    ~StakesTrap();
    void interact(Player& player, Field& field) override;
    Event* clone() const override;
};
