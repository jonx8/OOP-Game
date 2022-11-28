#pragma once
class Cell;

class CellView
{
private:
    char playerChar;
    char wallChar;
    char groundChar;
    char stakesChar;
    char victoryChar;

public:
    CellView() = default;
    CellView(char playerChar, char wallChar, char emptyChar);
    void printCell(Cell &cell) const;
    void setStakesChar(char symb);
    void setVictoryChar(char symb);
};