#pragma once
#include "MapEvent.h"
class EventsRegister;

class ExplodeEvent : public MapEvent
{
private:
    uint damage;
    EventsRegister *evReg;
    void pushPlayer(uint distance, Field &field) const;
    void cellsTraversal(Field &field) override;

public:
    ExplodeEvent(uint damage, uint radius, EventsRegister *evReg);
    ~ExplodeEvent();
    void interact(Player &player, Field &field) override;
    Event *clone() const override;
};
