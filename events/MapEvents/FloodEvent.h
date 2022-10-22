#pragma once
#include "MapEvent.h"
class EventsRegister;

class FloodEvent : public MapEvent
{
private:
    EventsRegister* evReg;
    void cellsTraversal(Field &field) override;

public:
    FloodEvent(uint radius, EventsRegister* evReg);
    ~FloodEvent();
    void interact(Player &player, Field &field) override;
    Event *clone() const override;
};
