#include "TrapEvent.h"

TrapEvent::TrapEvent(uint damage) : damage(damage) {}

TrapEvent::TrapEvent(const TrapEvent &obj) : TrapEvent(obj.damage) {}

TrapEvent::~TrapEvent() {}
