#include "EventsRegister.h"
#include "../events/TrapEvents/SpringTrap.h"
#include "../events/TrapEvents/StakesTrap.h"
#include "../events/GameOverEvents/VictoryEvent.h"
#include "../events/ItemEvents/ArmorEvent.h"
#include "../events/ItemEvents/HealEvent.h"
#include "../events/ItemEvents/StaminaEvent.h"

EventsRegister::EventsRegister()
{
    prototypes[Type::VICTORY_EVENT] = new VictoryEvent("Victory!");
    prototypes[Type::ARMOR_EVENT] = new ArmorEvent();
    prototypes[Type::HEAL_EVENT] = new HealEvent(25);
    prototypes[Type::STAMINA_EVENT] = new StaminaEvent(25);
    prototypes[Type::SPRING_EVENT] = new SpringTrap(2, 0);
    prototypes[Type::STAKES_EVENT] = new StakesTrap(40);
}

EventsRegister::~EventsRegister()
{
    delete prototypes[Type::VICTORY_EVENT];
    delete prototypes[Type::ARMOR_EVENT];
    delete prototypes[Type::HEAL_EVENT];
    delete prototypes[Type::STAMINA_EVENT];
    delete prototypes[Type::SPRING_EVENT];
    delete prototypes[Type::STAKES_EVENT];
}

Event *EventsRegister::getEvent(Type type)
{
    return prototypes[type]->clone();
}