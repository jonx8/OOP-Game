#include "Field.h"
#include "Cell.h"
#include "Player.h"
#include "../events/Event.h"

Field::Field(uint height, uint width) : height(height), width(width) {
    // Constructor with parameters
    for (size_t i = 0; i < height; ++i)
    {
        cells.emplace_back(std::vector<Cell>());
        for (size_t j = 0; j < width; ++j)
        {
            cells.back().emplace_back(Cell());
        }
    }
}

Field::Field(const Field &obj) : Field(obj.height, obj.width) {
    // Copy constructor
    player = obj.player;
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            cells[i][j] = obj.cells[i][j];
        }
    }
}

Field::Field(Field &&obj) noexcept {
    // Move constructor
    std::cout << "Hello, Move!\n";
    std::swap(player, obj.player);
    std::swap(height, obj.height);
    std::swap(width, obj.width);
    std::swap(playerCoords, obj.playerCoords);
    std::swap(cells, obj.cells);
    std::swap(observers_list, obj.observers_list);
}

Field &Field::operator=(const Field &obj) {
    // Copy assignment
    if (this != &obj)
    {
        height = obj.height;
        width = obj.width;
        cells = obj.cells;
        playerCoords = obj.playerCoords;
        player = obj.player;
        observers_list = obj.observers_list;
    }
    return *this;
}

Field &Field::operator=(Field &&obj) noexcept
{
    // Move assignment
    if (this != &obj)
    {
        std::swap(player, obj.player);
        std::swap(height, obj.height);
        std::swap(width, obj.width);
        std::swap(playerCoords, obj.playerCoords);
        std::swap(cells, obj.cells);
        std::swap(observers_list, obj.observers_list);
    }
    return *this;
}

Field::~Field()
{
    clearEvents();
}

void Field::clearEvents()
{
    for (const auto& row : cells)
    {
        for (auto cell : row)
        {
            if (cell.getEvent())
            {
                delete cell.getEvent();
                cell.setEvent(nullptr);
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

    if (getCell(newY, newX).getType() != Cell::Objects::WALL)
    {
        setPlayerCoord(newX, newY);
    }
    else
    {
        notify(Message("Player tried to move to impassable cell", Message::ERROR));
    }
}


uint Field::getHeight() const { return height; }

uint Field::getWidth() const { return width; }

std::pair<uint, uint> Field::getPlayerCoords() const { return playerCoords; }

Cell &Field::getCell(uint y, uint x) { return cells[y][x]; }

bool Field::playerInWater()
{
    if (cells[playerCoords.second][playerCoords.first].getType() == Cell::Objects::WATER)
    {
        return true;
    }
    return false;
}

void Field::setPlayer(Player *new_player) {
    player = new_player;
    player->addObserver(observers_list[0]);
    notify(Message("New player have been set", Message::GAME_STATUS));
}

void Field::eventCheck()
{
    cells[playerCoords.second][playerCoords.first].react(*player, *this);
}
