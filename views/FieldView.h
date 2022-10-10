#pragma once
#include "CellView.h"

class Field;
class FieldView
{
private:
    char borderChar;
    Field &field;
    CellView cellViewer;

public:
    explicit FieldView(Field &field);
    ~FieldView();
    void print() const;
    void printBorder() const;
    void setBorderChar(char symb);
};
