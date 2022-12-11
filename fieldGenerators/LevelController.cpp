#include "LevelController.h"

void LevelController::setMapTemplate(FieldType value) {
    map_template = value;
}

Field *LevelController::generateField(Player *player, Observer *obs) {
    if (map_template == FieldType::TWO_HUTS) {
        field = std::move(HutGen().getField());
    } else if (map_template == FieldType::LABIRINT) {
        field = std::move(LabirintGen().getField());
    } else if (map_template == FieldType::FORTRESS) {
        field = std::move(FortressGen().getField());
    } else {
        throw std::runtime_error("Incorrect type of field");
    }

    field.setPlayer(player);
    field.addObserver(obs);
    return &field;
}

void LevelController::setField(Field &new_field) {
    field = std::move(new_field);
}

