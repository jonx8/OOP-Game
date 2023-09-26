#pragma once

#include <random>
#include "../../models/Field.h"
#include "../../models/Cell.h"

template<uint num, Cell::Objects obj_type>
class ObjectsPosRule {
public:
    void operator()(Field &field) {
        const size_t max_iter = field.getHeight() * field.getWidth();
        for (size_t i = 0, obj_num = 0; i < max_iter && obj_num < num; i++) {
            int x = rand() % (field.getWidth() - 1);
            int y = rand() % (field.getHeight() - 1);
            Cell &curr_cell = field.getCell(y, x);
            if (!curr_cell.getEvent() and !curr_cell.hasPlayer() and curr_cell.isPassable()) {
                curr_cell.setType(obj_type);
                obj_num++;
            }
        }
    }
};
