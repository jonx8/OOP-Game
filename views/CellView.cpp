#include "CellView.h"
#include "../models/Cell.h"
#include "../events/GameOverEvents/VictoryEvent.h"
#include "../events/TrapEvents/StakesTrap.h"

CellView::CellView(char playerChar, char wallChar, char emptyChar) : playerChar(playerChar), wallChar(wallChar), emptyChar(emptyChar) {}

CellView::~CellView() {}

void CellView::printCell(Cell &cell) const
{

    if (cell.hasPlayer())
    {
        std::cout << playerChar;
    }
    else if (!cell.isPassable())
    {
        std::cout << wallChar;
    }
    else if (dynamic_cast<StakesTrap *>(cell.getEvent()))
    {
        std::cout << stakesChar;
    }
    else if (dynamic_cast<VictoryEvent *>(cell.getEvent()))
    {
        std::cout << '?';
    }
    else
    {
        std::cout << emptyChar;
    }
    std::cout << ' ';
}

void CellView::setStakesChar(char symb) { stakesChar = symb; }
void CellView::setVictoryChar(char symb) { victoryChar = symb; }
