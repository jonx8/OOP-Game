#pragma once
#include <iostream>
#include <vector>
#include <random>
typedef unsigned int uint;
class Cell;
class Player;
class EventsRegister;

class Field
{
private:
    uint height;
    uint width;
    std::pair<uint, uint> playerCoords; // x - first, y - second
    std::vector<std::vector<Cell>> cells;
    Player *player;

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
    void stdFieldGen(EventsRegister* evReg);
    void movePlayer(Directions direction);
    void eventCheck();
    bool playerInWater();
    Cell &getCell(int y, int x);
};
