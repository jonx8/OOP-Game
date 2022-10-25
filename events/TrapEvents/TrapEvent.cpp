#include "TrapEvent.h"

TrapEvent::TrapEvent(uint damage) : damage(damage) {}

TrapEvent::TrapEvent(const TrapEvent &obj) : TrapEvent(obj.damage) 
{
    observers_list = obj.observers_list;
}
TrapEvent::~TrapEvent()
{
}
