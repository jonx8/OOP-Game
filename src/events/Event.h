#pragma once

#include "../observable/Observable.h"

typedef unsigned int uint;

class Player;

class Field;

class Event : public Observable {
public:
    virtual ~Event() = 0;

    virtual void interact(Player &player, Field &field) = 0;

    [[nodiscard]] virtual Event *clone() const = 0;
};
