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

public:
    Controller(FieldView &fieldView, PlayerView &playerStatus, Field &gamefield, Player *player);
    ~Controller();
    void resetGame();
    void exitGame();
    void showField() const;
    void showPlayerStatus() const;
    void movePlayer(Field::Directions direction) const;
    void resetGame(std::pair<int, int> field_size);
    bool isVictory() const;
    bool isDefeat() const;
    
};
