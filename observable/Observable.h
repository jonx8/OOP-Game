#pragma once

#include <vector>
#include <string>
#include "../messages/Message.h"
#include "../observers/Observer.h"

using std::vector;

class Observer;

class Observable {
protected:

public:
    vector<Observer *> observers_list;

    virtual ~Observable() = 0;

    virtual void notify(const Message &msg);

    void addObserver(Observer *obs);

    void removeObserver(const std::string &observer_name);
};
