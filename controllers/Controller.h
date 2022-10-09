#pragma once
#include "../views/FieldView.h"
#include "../views/PlayerView.h"

class Controller
{
private:
    FieldView &fieldView;
    PlayerView& playerStatus;
    Field &gamefield;
    Player& player;
    

public:
    Controller(FieldView &fieldView, PlayerView& playerStatus, Field &gamefield, Player& player);
    ~Controller();
    void showField() const;
    void showPlayerStatus() const;
    void movePlayer(Field::directions direction) const;
    bool isVictory() const;
    bool isDefeat() const;
};
