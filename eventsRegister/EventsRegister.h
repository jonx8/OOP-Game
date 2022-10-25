#pragma once
#include <unordered_map>
#include <functional>
class Event;
class Observer;

enum Type
{
    VICTORY_EVENT,
    STAKES_EVENT,
    SPRING_EVENT,
    EXPLODE_EVENT,
    FLOOD_EVENT,
    DOOR_OPEN_EVENT,
    HEAL_EVENT,
    STAMINA_EVENT,
    ARMOR_EVENT,
};

class EventsRegister
{
private:
    std::unordered_map<Type, Event *, std::hash<int>> prototypes;
    Observer* obs;
public:
    EventsRegister(Observer* obs);
    ~EventsRegister();
    Event *getEvent(Type type);
};