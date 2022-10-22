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
    bool isPassable() const;
    bool hasPlayer() const;
    Event *getEvent() const;
    Objects getType() const;
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
