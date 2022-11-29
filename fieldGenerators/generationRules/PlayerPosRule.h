#pragma once

#include "../../models/Field.h"
#include "../../models/Cell.h"

template<uint y, uint x>
class PlayerPosRule {
public:
    void operator()(Field &field) {
        field.setPlayerCoord(0, 0);
        if (y < field.getHeight() - 1 && x < field.getWidth() - 1) {
            if (field.getCell(y, x).isPassable() && !field.getCell(y, x).getEvent()) {
                field.setPlayerCoord(x, y);
            }
        }
    }
};
