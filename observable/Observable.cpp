#include <iostream>
#include "Observable.h"

Observable::~Observable() = default;

void Observable::notify(const Message &msg) {
    for (auto i: observers_list) {
        i->update(msg);
    }
}

void Observable::addObserver(Observer *obs) {
    observers_list.emplace_back(obs);
}

void Observable::removeObserver(const std::string &observer_name) {
    for (size_t i = 0; i < observers_list.size(); i++) {
        if (observers_list[i]->getName() == observer_name) {
            observers_list.erase(observers_list.begin() + i);
            break;
        }
    }
}
