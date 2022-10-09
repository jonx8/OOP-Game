#pragma once
#include "../../models/Field.h"

class VictoryEvent : public Event
{
private:
protected:
    std::string msg;
    bool taken;

public:
    VictoryEvent(std::string msg, bool taken = false);
    void interact(Player &player);
    void interact(Field *field);
    bool isTaken() const;
};