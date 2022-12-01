#include "GameCreator.h"


void GameCreator::setMapTemplate(FieldType value) {
    map_template = value;
}

Field *GameCreator::generateField(Player *player, Observer *obs) {
    if (map_template == FieldType::TWO_HUTS) {
        field = std::move(StdHutGen().getField(player, obs));
    } else if (map_template == FieldType::LABIRINT) {
        field = std::move(StdLabirintGen().getField(player, obs));
    } else if (map_template == FieldType::FORTRESS) {
        StdLabirintGen generator;
        field = std::move(generator.getField(player, obs));
    } else {
        return nullptr;
    }
    return &field;
}
