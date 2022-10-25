#pragma once
#include "Controller.h"
#include "CommandReader.h"
#include "../loggers/Logger.h"
#include "../observers/Observer.h"

enum OBSERVERS
{
    READER_OBS,
    EVENTS_OBS,
    FIELD_OBS,
    PLAYER_OBS
};

using observers_map = std::unordered_map<OBSERVERS, Observer *, std::hash<int>>;

class Game
{
public:
    Game(Controller *controller, CommandReader *reader, observers_map &obs);
    ~Game();
    void start();
    void stop();
    void setObservers(observers_map &);


private:
    Controller *controller;
    CommandReader *reader;
    observers_map &observers;
    Logger *logger;
    bool running;
};
