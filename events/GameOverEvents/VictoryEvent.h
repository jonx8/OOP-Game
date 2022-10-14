#pragma once
#include <iostream>
#include "../Event.h"


class VictoryEvent : public Event
{
private:
    std::string msg;

public:
    explicit VictoryEvent(std::string msg);
    void interact(Player &player) override;
    void interact(Field &field) override;
    Event* clone() const override;
    std::string getMSG() const;
};