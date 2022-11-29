#pragma once

#include "Controller.h"
#include "readers/CommandReader.h"
#include "../observers/Observer.h"

//const char CONTROL_SETTINGS_FILE[] = "controlSettings.conf";

class Game {
private:
    Controller *controller;
    CommandReader *reader;
    ICommand *current_cmd;
public:
    Game(Controller *controller, CommandReader *reader);

    void start();
};
