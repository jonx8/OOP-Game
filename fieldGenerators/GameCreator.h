#pragma once

#include "FieldGenerator.h"
#include "generationRules/EventsPosRule.h"
#include "generationRules/FieldSizeRule.h"
#include "generationRules/PlayerPosRule.h"
#include "generationRules/ObjectPosRule.h"
#include "generationRules/MainBuildingRule.h"

class Player;

class Observer;

using StdHutGen = FieldGenerator<FieldSizeRule<25, 25>,
        MainBuildingRule<HUT, EventType::VICTORY_EVENT, 10, 10>,
        MainBuildingRule<HUT,
                EventType::EXPLODE_EVENT_BIG, 15, 15>,
        PlayerPosRule<10, 10>,
        ObjectsPosRule<20, Cell::Objects::GRASS>,
        ObjectsPosRule<30, Cell::Objects::WATER>,
        EventsPosRule<2, EventType::SPRING_EVENT>,
        EventsPosRule<10, EventType::STAKES_EVENT_BIG>>;

using StdLabirintGen = FieldGenerator<FieldSizeRule<20, 25>,
        MainBuildingRule<LABIRINT, EventType::VICTORY_EVENT, 10, 10>,
        PlayerPosRule<10, 10>,
        EventsPosRule<1, EventType::FLOOD_EVENT>,
        EventsPosRule<10, EventType::ARMOR_EVENT>,
        EventsPosRule<2, EventType::HEAL_EVENT>,
        ObjectsPosRule<5, Cell::Objects::WALL>,
        ObjectsPosRule<20, Cell::Objects::GRASS>,
        ObjectsPosRule<30, Cell::Objects::WATER>,
        EventsPosRule<2, EventType::EXPLODE_EVENT_BIG>,
        EventsPosRule<2, EventType::SPRING_EVENT>>;

class GameCreator {
private:
    Field field;
public:
    template<typename T>
    Field *generateField(Player *player, Observer *obs) {
        T generator;
        field = std::move(generator.getField(player, obs));
        return &field;
    }

};