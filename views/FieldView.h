#pragma once
#include "../models/Field.h"
#include "CellView.h"

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
