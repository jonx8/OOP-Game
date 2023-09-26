#include "FieldCorrector.h"
#include "../models/Field.h"
#include "../models/Cell.h"
#include "../events/GameOverEvents/VictoryEvent.h"

void FieldCorrector::playerPosFix(Field &field) const {
    auto [player_x, player_y] = field.getPlayerCoords();

    if (player_y > field.getHeight() - 1 || player_x > field.getWidth()) {
        field.setPlayerCoord(0, 0);
        player_x = 0;
        player_y = 0;
    }

    if (auto *ev = field.getCell(player_y, player_x).getEvent()) {
        delete ev;
        field.getCell(player_y, player_x).setEvent(nullptr);
    }

    field.getCell(player_y, player_x).setType(Cell::Objects::GROUND);

}

void FieldCorrector::VictoryCellFix(Field &field, uint x_pos, uint y_pos) const {
    // Diagonal length = min(field height and field width)
    uint diagonal_len = field.getHeight() ? field.getHeight() < field.getWidth() : field.getWidth();

    if (x_pos != y_pos) {
        delete field.getCell(y_pos, x_pos).getEvent();
        field.getCell(y_pos, x_pos).setEvent(nullptr);

        // Set standard victory event location
        y_pos = x_pos = diagonal_len - 1;
    }


    for (int coord = 1; coord < diagonal_len - 1; ++coord) {
        auto &curr_cell = field.getCell(coord, coord);
        curr_cell.setType(Cell::Objects::GROUND);
        field.getCell(coord + 1, coord).setType(Cell::Objects::GROUND);

        if (x_pos == coord) {

        }
    }
}

bool FieldCorrector::validateField(Field &field) {
    auto [player_y, player_x] = field.getPlayerCoords();
    if (player_y < field.getHeight() and player_x < field.getWidth()) {
        return false;
    }

    bool hasVictoryEvent = false;

    for (int y = 0; y < field.getHeight(); ++y) {
        for (int x = 0; x < field.getWidth(); ++x) {
            if (dynamic_cast<VictoryEvent *>(field.getCell(y, x).getEvent()) != nullptr) {
                hasVictoryEvent = true;
                if ((y == player_y and x == player_x)) {
                    return false;
                }
            }
        }
    }

    return hasVictoryEvent;
}


