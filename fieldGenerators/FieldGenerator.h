#pragma once
#include "../models/Field.h"

template <typename... Rules>
class FieldGenerator
{
private:
    Field field;

public:
    FieldGenerator() : field(Field(20, 20)) {}
    Field &getField(Player *player, Observer *obs)
    {
        (Rules()(field), ...);
        field.addObserver(obs);
        field.setPlayer(player);
        return field;
    }
};
