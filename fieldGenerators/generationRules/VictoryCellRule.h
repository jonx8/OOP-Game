#pragma once

#include "../../models/Field.h"
#include "../../models/Cell.h"
#include "../../events/Event.h"

template<int y, int x>
class VictoryCellRule {
public:
    void operator()(Field &field) {
        uint y_normal = (y + field.getHeight()) % field.getHeight();
        uint x_normal = (x + field.getWidth()) % field.getWidth();

        if (field.getCell(y_normal, x_normal).getEvent()) {
            delete field.getCell(y_normal, x_normal).getEvent();
        }
        if (field.getPlayerCoords().first == x_normal and field.getPlayerCoords().second == y_normal) {
            throw std::runtime_error("Player coordinates and VictoryEvent coordinates are match!");
        }
        field.getCell(y_normal, x_normal).setEvent(EventsRegister::getReg().getEvent(VICTORY_EVENT));
        field.getCell(y_normal, x_normal).setType(Cell::Objects::GROUND);


    }

};