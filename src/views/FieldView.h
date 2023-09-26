#pragma once

#include "CellView.h"

class Field;

class FieldView {
private:
    char borderChar;
    Field *field;
    CellView cellViewer;

public:
    explicit FieldView(Field *field = nullptr);

    void print() const;

    void printBorder() const;

    void setField(Field *field);

    void setBorderChar(char symb);
};
