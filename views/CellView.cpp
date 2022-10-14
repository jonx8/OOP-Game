#include "CellView.h"
#include "../models/Cell.h"
#include "../events/GameOverEvents/VictoryEvent.h"
#include "../events/TrapEvents/StakesTrap.h"
#include "../events/TrapEvents/SpringTrap.h"
#include "../events/ItemEvents/ArmorEvent.h"
#include "../events/MapEvents/ExplodeEvent.h"
#include "../events/ItemEvents/HealEvent.h"

CellView::CellView(char playerChar, char wallChar, char groundChar) : playerChar(playerChar), wallChar(wallChar), groundChar(groundChar) {}

CellView::~CellView() {}

void CellView::printCell(Cell &cell) const
{
    if (cell.hasPlayer())
    {
        std::cout << playerChar;
    }
    else if (cell.getType() == Cell::Objects::WALL)
    {
        std::cout << wallChar;
    }
    else if (cell.getType() == Cell::Objects::WATER)
    {
        std::cout << '~';
    }
    else if (cell.getType() == Cell::Objects::GRASS)
    {
        std::cout << '"';
    }

    else if (dynamic_cast<StakesTrap *>(cell.getEvent()))
    {
        std::cout << stakesChar;
    }
    else if (dynamic_cast<SpringTrap *>(cell.getEvent()))
    {
        std::cout << '&';
    }
    else if (dynamic_cast<VictoryEvent *>(cell.getEvent()))
    {
        std::cout << '?';
    }
    else if (dynamic_cast<ArmorEvent *>(cell.getEvent()))
    {
        std::cout << 'A';
    }
    else if (dynamic_cast<ExplodeEvent *>(cell.getEvent()))
    {
        std::cout << 'E';
    }
    else if (dynamic_cast<HealEvent *>(cell.getEvent()))
    {
        std::cout << 'H';
    }
    else
    {
        std::cout << groundChar;
    }
    std::cout << ' ';
}

void CellView::setStakesChar(char symb) { stakesChar = symb; }
void CellView::setVictoryChar(char symb) { victoryChar = symb; }
