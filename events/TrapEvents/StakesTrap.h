#pragma once
#include "TrapEvent.h"

class StakesTrap : public TrapEvent
{
public:
    using TrapEvent::TrapEvent;
    ~StakesTrap();
    void interact(Player& player) override;
    void interact(Field& field) override;
    Event* clone() const override;
};
