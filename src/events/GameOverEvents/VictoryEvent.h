#pragma once

#include <iostream>
#include "../Event.h"

class VictoryEvent : public Event {
private:
    std::string msg;

public:
    explicit VictoryEvent(std::string msg);

    ~VictoryEvent() override = default;

    void interact(Player &player, Field &field) override;

    [[nodiscard]] Event *clone() const override;

    [[nodiscard]] std::string getMSG() const;
};