#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include "../eventsRegister/EventsRegister.h"
#include "../observable/Observable.h"

using uint = unsigned int;

class Cell;

class Player;

class Field : public Observable {
private:
    uint height;
    uint width;
    std::pair<uint, uint> playerCoords; // x - first, y - second
    std::vector<std::vector<Cell>> cells;
    Player *player;

public:
    enum class Directions {
        LEFT,
        RIGHT,
        DOWN,
        UP
    };
    explicit Field(uint height = 20, uint width = 20);

    Field(const Field &obj);

    Field(Field &&obj) noexcept;

    ~Field() override;

    Field &operator=(const Field &obj);

    Field &operator=(Field &&obj) noexcept;

    [[nodiscard]] uint getHeight() const;

    [[nodiscard]] uint getWidth() const;

    [[nodiscard]] std::pair<uint, uint> getPlayerCoords() const;

    void setPlayerCoord(uint CoordX, uint CoordY);

    void clearEvents();

    void setPlayer(Player *player);

    void movePlayer(Directions direction);

    void eventCheck();

    bool playerInWater();

    Cell &getCell(uint y, uint x);
};
