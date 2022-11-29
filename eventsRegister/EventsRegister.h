#pragma once

#include <unordered_map>
#include <functional>

class Event;

class Observer;

enum EventType {
    VICTORY_EVENT,
    STAKES_EVENT_SMALL,
    STAKES_EVENT_BIG,
    SPRING_EVENT,
    EXPLODE_EVENT_SMALL,
    EXPLODE_EVENT_BIG,
    FLOOD_EVENT,
    DOOR_OPEN_EVENT,
    HEAL_EVENT,
    STAMINA_EVENT,
    ARMOR_EVENT,
};

class EventsRegister {
private:
    std::unordered_map<EventType, Event *, std::hash<int>> prototypes;

    EventsRegister();

    ~EventsRegister();

public:
    EventsRegister(const EventsRegister &) = delete;

    EventsRegister &operator=(EventsRegister &) = delete;

    static EventsRegister &getReg();

    void addEventObserver(Observer *obs);

    Event *getEvent(EventType type);
};