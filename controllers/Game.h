#pragma once
#include "Controller.h"
#include "CommandReader.h"

class Game
{
private:
    Controller *controller;
    CommandReader *reader;
    bool running;

public:
    Game(Controller *controller, CommandReader *reader);
    ~Game();
    void start();
    void stop();
};
