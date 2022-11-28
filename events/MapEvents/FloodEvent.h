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
    FloodEvent(const FloodEvent& obj);
    ~FloodEvent() override = default;
    void interact(Player &player, Field &field) override;
    [[nodiscard]] Event *clone() const override;
};
