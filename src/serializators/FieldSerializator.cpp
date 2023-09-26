#include <iostream>
#include <fstream>
#include "FieldSerializator.h"
#include "../models/Field.h"
#include "../models/Cell.h"


bool FieldSerializator::serialize(const std::string &filename, Field field) {

    std::ofstream out;
    out.open(filename);
    if (out.is_open()) {
        field.clearObs();
        out.write(reinterpret_cast<char *>(&field), sizeof(Field));
        for (size_t y = 0; y < field.getHeight(); ++y) {
            for (size_t x = 0; x < field.getWidth(); ++x) {
                field.getCell(y, x).setEvent(nullptr);
                out.write(reinterpret_cast<char *>(&(field.getCell(y, x))), sizeof(Cell));
            }
        }
        out.close();
    } else {
        return false;
    }
    return true;
}

Field FieldSerializator::deserialize(const std::string &filename) {
    Field field;
    std::ifstream in;
    in.open(filename);
    if (in.is_open()) {
        in.read(reinterpret_cast<char *>(&field), sizeof(Field));
        for (size_t i = 0; i < field.height; ++i) {
            field.cells.emplace_back(std::vector<Cell>());
            for (size_t j = 0; j < field.width; ++j) {
                field.cells.back().emplace_back(Cell());
            }
        }

        for (size_t y = 0; y < field.height; ++y) {
            for (size_t x = 0; x < field.width; ++x) {
                in.read(reinterpret_cast<char *>(&field.cells[y][x]), sizeof(Cell));
            }
        }
        in.close();
    } else {
        throw std::runtime_error("Cannot open file");
    }
    return field;
}
