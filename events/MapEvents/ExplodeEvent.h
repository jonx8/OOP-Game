#pragma once
#include "MapEvent.h"
class EventsRegister;

class ExplodeEvent : public MapEvent
{
private:
    uint damage;
    EventsRegister *evReg;
    static void pushPlayer(uint distance, Field &field) ;
    void cellsTraversal(Field &field) override;

public:
    ExplodeEvent(uint damage, uint radius, EventsRegister *evReg);
    ExplodeEvent(const ExplodeEvent &obj);
    ~ExplodeEvent() override = default;
    void interact(Player &player, Field &field) override;
    [[nodiscard]] Event *clone() const override;
};
