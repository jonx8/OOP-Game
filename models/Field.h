#pragma once
#include <random>
#include <vector>
#include "Cell.h"
#include "Player.h"
#include "../builders/VictoryEventBuilder.h"
#include "../builders/TrapEventBuilder.h"


class Field
{
private:
    uint height;
    uint width;
    std::pair<uint, uint> playerCoords; // x - first, y - second
    std::vector<std::vector<Cell>> cells;
    Player *player;

public:
    enum directions
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
    void setPlayerCoord(uint CoordX, uint CoordY);
    void stdFieldGen();
    void movePlayer(directions direction);
    Cell &getCell(int y, int x);
};
