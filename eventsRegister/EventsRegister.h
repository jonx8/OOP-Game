#pragma once
#include <unordered_map>
#include <functional>
class Event;
enum Type
{
    VICTORY_EVENT,
    STAKES_EVENT,
    SPRING_EVENT,
    EXPLODE_EVENT,
    HEAL_EVENT,
    STAMINA_EVENT,
    ARMOR_EVENT,
};
class EventsRegister
{
public:
    EventsRegister();
    ~EventsRegister();
    Event *getEvent(Type type);

private:
    std::unordered_map<Type, Event *, std::hash<int>> prototypes;
};