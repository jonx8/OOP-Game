#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "../eventsRegister/EventsRegister.h"
#include "../observable/Observable.h"
typedef unsigned int uint;
class Cell;
class Player;

class Field : public Observable
{
private:
    uint height;
    uint width;
    std::pair<uint, uint> playerCoords; // x - first, y - second
    std::vector<std::vector<Cell>> cells;
    Player *player;
    EventsRegister *evReg;

public:
    enum class Directions
    {
        LEFT,
        RIGHT,
        DOWN,
        UP
    };
    Field();
    Field(uint height, uint width, Player *player);
    Field(const Field &obj);
    Field(Field &&obj);
    ~Field();
    Field &operator=(const Field &obj);
    Field &operator=(Field &&obj);
    uint getHeight() const;
    uint getWidth() const;
    std::pair<uint, uint> getPlayerCoords() const;
    void setPlayerCoord(uint CoordX, uint CoordY);
    void stdFieldGen();
    void randomFieldGen();
    void movePlayer(Directions direction);
    void eventCheck();
    Event *eventGenerate(Type type);
    void setEventRegister(EventsRegister *eventRegister);
    bool playerInWater();
    Cell &getCell(int y, int x);
    void notify(const Message& msg) override;
};
