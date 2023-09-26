#pragma once

#include "TrapEvent.h"

class SpringTrap : public TrapEvent {
private:
    uint pushDist;

public:
    SpringTrap(uint pushDist, uint damage);

    SpringTrap(const SpringTrap &obj);

    ~SpringTrap() override = default;

    void interact(Player &player, Field &field) override;

    [[nodiscard]] Event *clone() const override;
};
