#pragma once

#include "FieldGenerator.h"
#include "generationRules/EventsPosRule.h"
#include "generationRules/FieldSizeRule.h"
#include "generationRules/PlayerPosRule.h"
#include "generationRules/ObjectPosRule.h"
#include "generationRules/MainBuildingRule.h"
#include "generationRules/VictoryCellRule.h"

class Player;

class Observer;

using HutGen = FieldGenerator<FieldSizeRule<25, 25>,
        MainBuildingRule<HUT, 10, 10>,
        MainBuildingRule<HUT, 15, 15>,
        PlayerPosRule<3, 3>,
        ObjectsPosRule<20, Cell::Objects::GRASS>,
        ObjectsPosRule<30, Cell::Objects::WATER>,
        EventsPosRule<2, EventType::SPRING_EVENT>,
        EventsPosRule<10, EventType::STAKES_EVENT_BIG>,
        VictoryCellRule<19, 19>>;

using LabirintGen = FieldGenerator<FieldSizeRule<20, 25>,
        MainBuildingRule<LABIRINT, 10, 10>,
        PlayerPosRule<10, 10>,
        EventsPosRule<1, EventType::FLOOD_EVENT>,
        EventsPosRule<10, EventType::ARMOR_EVENT>,
        EventsPosRule<2, EventType::HEAL_EVENT>,
        ObjectsPosRule<5, Cell::Objects::WALL>,
        ObjectsPosRule<20, Cell::Objects::GRASS>,
        ObjectsPosRule<30, Cell::Objects::WATER>,
        EventsPosRule<2, EventType::EXPLODE_EVENT_BIG>,
        EventsPosRule<2, EventType::SPRING_EVENT>,
        VictoryCellRule<19, 19>>;

using FortressGen = FieldGenerator<FieldSizeRule<20, 20>,
        PlayerPosRule<0, 0>,
        MainBuildingRule<FORTRESS, 4, 4>,
        EventsPosRule<1, EventType::FLOOD_EVENT>,
        EventsPosRule<10, EventType::ARMOR_EVENT>,
        EventsPosRule<2, EventType::HEAL_EVENT>,
        ObjectsPosRule<5, Cell::Objects::WALL>,
        ObjectsPosRule<20, Cell::Objects::GRASS>,
        ObjectsPosRule<30, Cell::Objects::WATER>,
        EventsPosRule<5, EventType::EXPLODE_EVENT_BIG>,
        EventsPosRule<2, EventType::SPRING_EVENT>,
        VictoryCellRule<19, 19>>;


enum class FieldType {
    TWO_HUTS = 1,
    LABIRINT,
    FORTRESS,
};

class LevelCreator {
private:
    Field field;
    FieldType map_template;
public:
    void setMapTemplate(FieldType value);

    Field *generateField(Player *player, Observer *obs);
};