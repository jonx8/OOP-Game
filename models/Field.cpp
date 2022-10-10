#include "Field.h"
#include <random>
#include "Cell.h"
#include "Player.h"
#include "../builders/VictoryEventBuilder.h"
#include "../builders/TrapEventBuilder.h"


// Default constructor
Field::Field() : height(0), width(0), player(new Player()){};

Field::Field(uint height, uint width, Player *player) : height(height), width(width), playerCoords(0, 0), player(player)
{
    // Constructor with parameters
    for (size_t i = 0; i < height; ++i)
    {
        cells.push_back(std::vector<Cell>());
        for (size_t j = 0; j < width; ++j)
        {
            cells.back().emplace_back(Cell());
        }
    }
};

Field::Field(const Field &obj) : Field(obj.height, obj.width, obj.player)
{
    // Copy constructor
    player = obj.player;
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            cells[i][j] = obj.cells[i][j];
        }
    }
};

Field::Field(Field &&obj)
{
    // Move constructor
    std::swap(player, obj.player);
    std::swap(height, obj.height);
    std::swap(width, obj.width);
    std::swap(cells, obj.cells);
};

Field &Field::operator=(const Field &obj)
{
    // Copy assignment
    if (this != &obj)
    {
        height = obj.height;
        width = obj.width;
        cells = obj.cells;
        playerCoords = obj.playerCoords;
        player = obj.player;
    }
    return *this;
}

Field &Field::operator=(Field &&obj)
{
    // Move assignment
    if (this != &obj)
    {
        std::swap(height, obj.height);
        std::swap(width, obj.width);
        std::swap(cells, obj.cells);
        std::swap(playerCoords, obj.playerCoords);
        std::swap(player, obj.player);
    }
    return *this;
}

Field::~Field(){};

void Field::setPlayerCoord(uint CoordX, uint CoordY)
{

    getCell(playerCoords.second, playerCoords.first).removePlayer();
    playerCoords.first = CoordX;
    playerCoords.second = CoordY;
    getCell(playerCoords.second, playerCoords.first).addPlayer();
}

void Field::movePlayer(directions direction)
{
    uint newX = playerCoords.first;
    uint newY = playerCoords.second;

    // if a player has crossed the edge of the field, then he must go out on the other side

    switch (direction)
    {
    case UP:
        newY = (newY + height - 1) % height;
        break;
    case DOWN:
        newY = (newY + 1) % height;
        break;
    case LEFT:
        newX = (newX + width - 1) % width;
        break;
    case RIGHT:
        newX = (newX + 1) % width;
        break;
    }

    if (getCell(newY, newX).isPassable())
    {
        setPlayerCoord(newX, newY);
        getCell(newY, newX).react(*player);
        getCell(newY, newX).react(*this);
    }

    if (player->isDead())
    {
        std::cout << "Game Over!" << std::endl;
    }
}

uint Field::getHeight() const { return height; }
uint Field::getWidth() const { return width; }

void Field::stdFieldGen()
{
    int x = 1, y = 1;

    for (size_t i = 0; i < (height * width) / 5; i++)
    {
        y = rand() % (height - 1) + 1;
        x = rand() % (width - 1) + 1;
        getCell(y, x).setPassable(false);
    }

    do
    {
        y = rand() % (height - 1) + 1;
        x = rand() % (width - 1) + 1;
    } while (getCell(y, x).hasPlayer() || !getCell(y, x).isPassable());

    // Events
    TrapEventBuilder stakesFabric(35);
    stakesFabric.buildStakes();
    VictoryEventBuilder victoryBuilder("Victory!");
    Event *v = victoryBuilder.create();
    Event *ev1 = stakesFabric.create();

    getCell(4, 4).setEvent(ev1);
    getCell(4, 5).setEvent(ev1);
    getCell(4, 6).setEvent(ev1);
    getCell(4, 7).setEvent(ev1);
    getCell(5, 4).setEvent(ev1);
    getCell(14, 7).setEvent(v);
    // Need freeing
}
Cell &Field::getCell(int y, int x) { return cells[y][x]; }