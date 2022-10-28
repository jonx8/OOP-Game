#include "StaminaEvent.h"

StaminaEvent::StaminaEvent(int value) : value(value) {}
StaminaEvent::StaminaEvent(const StaminaEvent &obj) : ItemEvent::ItemEvent(obj)
{
    value = obj.value;
}
StaminaEvent::~StaminaEvent() {}

void StaminaEvent::interact(Player &player, Field &field)
{
    notify(Message("StaminaEvent executed", Message::INFO));
    player.changeHealth(value);
}

Event *StaminaEvent::clone() const
{
    return new StaminaEvent(*this);
}