#pragma once
#include "../models/Cell.h"
#include "../events/TrapEvents/StakesTrap.h"
#include "../events/GameOverEvents/VictoryEvent.h"

class CellView
{
private:
    char playerChar;
    char wallChar;
    char emptyChar;
    char stakesChar;
    char victoryChar;

public:
    CellView() = default;
    CellView(char playerChar, char wallChar, char emptyChar);
    ~CellView();
    void printCell(Cell &cell) const;
    void setStakesChar(char symb);
    void setVictoryChar(char symb);
};