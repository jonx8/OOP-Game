#pragma once
#include <vector>
#include <string>
#include "../messages/Message.h"
#include "../observers/Observer.h"

using std::vector;
class Observer;

class Observable
{
protected:
    vector<Observer *> observers_list;

public:
    virtual ~Observable() = 0;
    virtual void notify(const Message &msg);
    void addObserver(Observer *obs);
    void removeObserver(std::string observer_name);
};
