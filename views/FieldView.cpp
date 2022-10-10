#include "FieldView.h"
#include "../models/Field.h"


FieldView::FieldView(Field &field) : field(field), cellViewer(CellView('P', '#', ' '))
{
    cellViewer.setStakesChar('^');
    cellViewer.setVictoryChar('V');
}

FieldView::~FieldView(){};

void FieldView::print() const
{
    printBorder();
    for (size_t i = 0; i < field.getHeight(); i++)
    {
        std::cout << borderChar << ' ';
        for (size_t j = 0; j < field.getWidth(); j++)
        {
            cellViewer.printCell(field.getCell(i, j));
        }
        std::cout << borderChar << '\n';
    }
    printBorder();
}

void FieldView::printBorder() const
{
    for (size_t i = 0; i <= field.getWidth() + 1; i++)
    {
        std::cout << borderChar;
        std::cout << ' ';
    }
    std::cout << '\n';
}

void FieldView::setBorderChar(char symb) { borderChar = symb; }