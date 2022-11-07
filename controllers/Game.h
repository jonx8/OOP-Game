#pragma once
#include "Controller.h"
#include "readers/CommandReader.h"
#include "../observers/Observer.h"

const char CONTROL_SETTINGS_FILE[] = "controlSettings.conf";

class Game
{
private:
    Controller *controller;
    CommandReader *reader;
    Observer *observer;
    bool running;

public:
    Game(Controller *controller, CommandReader *reader, Observer *obs);
    ~Game();
    void start();
    void stop();
    void setObserver(Observer *obs);
};
