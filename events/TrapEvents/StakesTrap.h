#pragma once
#include "TrapEvent.h"

class StakesTrap : public TrapEvent
{
public:
    using TrapEvent::TrapEvent;
    ~StakesTrap();
    void interact(Field& field) override;
};
