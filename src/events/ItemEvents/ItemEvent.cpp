#include "ItemEvent.h"

ItemEvent::ItemEvent(const ItemEvent &obj) : Event(obj) {
    observers_list = obj.observers_list;
}

ItemEvent::~ItemEvent() {}
