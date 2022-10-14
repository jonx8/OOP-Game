#include "Field.h"
#include "Cell.h"
#include "Player.h"
#include "../eventsRegister/EventsRegister.h"

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

Field::~Field()
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (getCell(i, j).getEvent())
            {
                // delete getCell(i, j).getEvent();
            }
        }
    }
}

void Field::setPlayerCoord(uint CoordX, uint CoordY)
{

    getCell(playerCoords.second, playerCoords.first).removePlayer();
    playerCoords.first = CoordX;
    playerCoords.second = CoordY;
    getCell(playerCoords.second, playerCoords.first).addPlayer();
}

void Field::movePlayer(Directions direction)
{
    uint newX = playerCoords.first;
    uint newY = playerCoords.second;

    // if the player has crossed the edge of the field, then he must go out on a other side

    switch (direction)
    {
    case Directions::UP:
        newY = (newY + height - 1) % height;
        break;
    case Directions::DOWN:
        newY = (newY + 1) % height;
        break;
    case Directions::LEFT:
        newX = (newX + width - 1) % width;
        break;
    case Directions::RIGHT:
        newX = (newX + 1) % width;
        break;
    }

    if (getCell(newY, newX).isPassable())
    {
        setPlayerCoord(newX, newY);
    }
}

uint Field::getHeight() const { return height; }

uint Field::getWidth() const { return width; }

std::pair<uint, uint> Field::getPlayerCoords() const { return playerCoords; }

void Field::stdFieldGen(EventsRegister *evReg)
{
    // Generate lake
    uint lakeX = rand() % static_cast<int>(width * 0.75) + static_cast<int>(width * 0.25);
    uint lakeY = rand() % static_cast<int>(height * 0.75) + static_cast<int>(height * 0.25);
    uint lakeSize = rand() % (height * width / 10) + 10;
    uint radius = sqrt(lakeSize) / 2;

    for (size_t y = lakeY - radius; y < lakeY + radius; y++)
    {
        for (size_t x = lakeX - radius; x < lakeX + radius; x++)
        {
            if ((rand() % 100 + 1) < 79)
            {
                cells[(y + height) % height][(x + width) % width].setType(Cell::Objects::WATER);
            }
        }
    }

    // Generate walls
    uint wallNum = 8;
    for (size_t i = 0; i < wallNum; i++)
    {
        int x = rand() % (width - 1);
        int y = rand() & (height - 1);
        int d = rand() % 2 - 1;
        for (size_t j = x; j < x + 4; j++, d += (rand() % 4 - 4))
        {
            if (cells[((y + d) + height) % height][(j + width) % width].getType() == Cell::Objects::GROUND)
            {
                cells[((y + d) + height) % height][(j + width) % width].setType(Cell::Objects::WALL);
                cells[((y + d) + height) % height][(j + width) % width].setPassable(false);
            }
        }
    }

    // Generate grass
    int grassNum = 5;

    for (size_t i = 0; i < grassNum; i++)
    {
        int x = rand() % (width - 2);
        int y = rand() & (height - 2);
        if (cells[y][x].getType() == Cell::Objects::GROUND && cells[y + 1][x + 1].getType() == Cell::Objects::GROUND)
        {
            cells[(y + height) % height][(x + width) % width].setType(Cell::Objects::GRASS);
            cells[(y + height) % height][(x + width) % width].setPassable(true);

            cells[(y + height + 1) % height][(x + width) % width].setType(Cell::Objects::GRASS);
            cells[(y + height + 1) % height][(x + width) % width].setPassable(true);

            cells[(y + height) % height][(x + width + 1) % width].setType(Cell::Objects::GRASS);
            cells[(y + height) % height][(x + width + 1) % width].setPassable(true);

            cells[(y + height + 1) % height][(x + width + 1) % width].setType(Cell::Objects::GRASS);
            cells[(y + height + 1) % height][(x + width + 1) % width].setPassable(true);
        }
        else
        {
            i--;
        }
        cells[2][3].setEvent(evReg->getEvent(VICTORY_EVENT));
    }
}

Cell &Field::getCell(int y, int x) { return cells[y][x]; }

bool Field::playerInWater()
{
    if (cells[playerCoords.second][playerCoords.first].getType() == Cell::Objects::WATER)
    {
        return true;
    }
    return false;
}

void Field::eventCheck()
{
    cells[playerCoords.second][playerCoords.first].react(*player);
    cells[playerCoords.second][playerCoords.first].react(*this);
}