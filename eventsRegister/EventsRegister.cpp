#include "EventsRegister.h"
#include "../events/TrapEvents/SpringTrap.h"
#include "../events/TrapEvents/StakesTrap.h"
#include "../events/GameOverEvents/VictoryEvent.h"
#include "../events/ItemEvents/ArmorEvent.h"
#include "../events/ItemEvents/HealEvent.h"
#include "../events/ItemEvents/StaminaEvent.h"
#include "../events/MapEvents/ExplodeEvent.h"
#include "../events/MapEvents/FloodEvent.h"
#include "../events/MapEvents/DoorOpenEvent.h"

EventsRegister::EventsRegister(Observer *obs) : obs(obs)
{
    prototypes[VICTORY_EVENT] = new VictoryEvent("Victory!");
    prototypes[ARMOR_EVENT] = new ArmorEvent();
    prototypes[HEAL_EVENT] = new HealEvent(25);
    prototypes[STAMINA_EVENT] = new StaminaEvent(25);
    prototypes[SPRING_EVENT] = new SpringTrap(2, 0);
    prototypes[STAKES_EVENT] = new StakesTrap(40);
    prototypes[EXPLODE_EVENT] = new ExplodeEvent(80, 3, this);
    prototypes[FLOOD_EVENT] = new FloodEvent(7, this);
    prototypes[DOOR_OPEN_EVENT] = new DoorOpenEvent(this);
    for (auto i : prototypes)
    {
        i.second->addObserver(obs);
    }
    
    
}

EventsRegister::~EventsRegister()
{
    delete prototypes[VICTORY_EVENT];
    delete prototypes[ARMOR_EVENT];
    delete prototypes[HEAL_EVENT];
    delete prototypes[STAMINA_EVENT];
    delete prototypes[SPRING_EVENT];
    delete prototypes[STAKES_EVENT];
    delete prototypes[EXPLODE_EVENT];
    delete prototypes[FLOOD_EVENT];
}

Event *EventsRegister::getEvent(Type type)
{
    return prototypes[type]->clone();
}