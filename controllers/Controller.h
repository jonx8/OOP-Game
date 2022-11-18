#pragma once
#include "../models/Field.h"
class FieldView;
class PlayerView;
class Field;
class Player;

class Controller
{
private:
    FieldView &fieldView;
    PlayerView &playerStatus;
    Field &gamefield;
    Player *player;
    Observer *observer;
    bool running;
public:
    Controller(FieldView &fieldView, PlayerView &playerStatus, Field &gamefield, Player *player);
    ~Controller();
    void startGame(); 
    void resetGame();
    void exitGame();
    void setObserver(Observer *obs);
    void showField() const;
    void showPlayerStatus() const;
    void movePlayer(Field::Directions direction) const;
    bool isVictory() const;
    bool isDefeat() const;
    bool isRunning() const;
};
