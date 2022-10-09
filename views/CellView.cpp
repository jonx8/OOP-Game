#include "CellView.h"

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
        if (dynamic_cast<VictoryEvent *>(cell.getEvent())->isTaken())
        {
            std::cout << victoryChar;
        }
        else
        {
            std::cout << '?';
        }

    }
    else
    {
        std::cout << emptyChar;
    }
    std::cout << ' ';
}

void CellView::setStakesChar(char symb) { stakesChar = symb; }
void CellView::setVictoryChar(char symb) { victoryChar = symb; }
