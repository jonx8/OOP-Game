#pragma once

#include "../models/Field.h"
#include "../models/Cell.h"

template<typename... Rules>
class FieldGenerator {
private:
    Field field;
public:
    FieldGenerator() : field(Field(20, 20)) {}

    ~FieldGenerator() {
        for (size_t y = 0; y < field.getHeight(); ++y) {
            for (size_t x = 0; x < field.getWidth(); ++x) {
                field.getCell(y, x).setEvent(nullptr);
            }
        }
    }

    Field getField(Player *player, Observer *obs) {
        (Rules()(field), ...);
        field.addObserver(obs);
        field.setPlayer(player);
        return field;
    }
};
