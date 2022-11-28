#pragma once
class Event;
class Player;
class Field;

class Cell
{
public:
    enum class Objects
    {
        GROUND,
        WALL,
        GRASS,
        WATER,
    };
    Cell();
    [[nodiscard]] bool isPassable() const;
    [[nodiscard]] bool hasPlayer() const;
    [[nodiscard]] Event *getEvent() const;
    [[nodiscard]] Objects getType() const;
    void react(Player &player, Field &field);
    void setEvent(Event *ev);
    void addPlayer();
    void removePlayer();
    void setPassable(bool value);
    void setType(Objects value);

private:
    bool passable;
    bool playerOnCell;
    Objects type;
    Event *event;
};
