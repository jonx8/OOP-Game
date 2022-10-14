#pragma once
#include "MapEvent.h"

class FloodEvent : public MapEvent
{
private:
    void cellsTraversal(Field &field) override;

public:
    FloodEvent(uint radius);
    ~FloodEvent();
    void interact(Player &player) override;
    void interact(Field &field) override;
    Event *clone() const override;
};
