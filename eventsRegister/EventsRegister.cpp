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

EventsRegister::EventsRegister() {
    prototypes[VICTORY_EVENT] = new VictoryEvent("Victory!");
    prototypes[ARMOR_EVENT] = new ArmorEvent();
    prototypes[HEAL_EVENT] = new HealEvent(25);
    prototypes[STAMINA_EVENT] = new StaminaEvent(25);
    prototypes[SPRING_EVENT] = new SpringTrap(2, 0);
    prototypes[STAKES_EVENT_SMALL] = new StakesTrap(40);
    prototypes[STAKES_EVENT_BIG] = new StakesTrap(80);
    prototypes[EXPLODE_EVENT_SMALL] = new ExplodeEvent(80, 3, this);
    prototypes[EXPLODE_EVENT_BIG] = new ExplodeEvent(80, 5, this);
    prototypes[FLOOD_EVENT] = new FloodEvent(7, this);
    prototypes[DOOR_OPEN_EVENT] = new DoorOpenEvent(this);
}

EventsRegister::~EventsRegister() {
    delete prototypes[VICTORY_EVENT];
    delete prototypes[ARMOR_EVENT];
    delete prototypes[HEAL_EVENT];
    delete prototypes[STAMINA_EVENT];
    delete prototypes[SPRING_EVENT];
    delete prototypes[STAKES_EVENT_SMALL];
    delete prototypes[STAKES_EVENT_BIG];
    delete prototypes[EXPLODE_EVENT_SMALL];
    delete prototypes[EXPLODE_EVENT_BIG];
    delete prototypes[FLOOD_EVENT];
}

Event *EventsRegister::getEvent(EventType type) {
    return prototypes[type]->clone();
}

EventsRegister &EventsRegister::getReg() {
    static EventsRegister evReg;
    return evReg;
}

void EventsRegister::addEventObserver(Observer *obs) {
    for (auto i: prototypes) {
        i.second->addObserver(obs);
    }
}