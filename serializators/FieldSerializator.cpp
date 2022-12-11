#include <iostream>
#include <fstream>
#include "FieldSerializator.h"
#include "../models/Field.h"

bool FieldSerializator::serialize(const std::string &filename, Field *field) {

    std::ofstream out;
    out.open(filename);
    if (out.is_open()) {
        field->clearObs();
        out.write(reinterpret_cast<char *>(field), sizeof(Field));
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
        std::cout << sizeof(Field) << std::endl;
        in.read(reinterpret_cast<char *>(&field), sizeof(Field));
    } else {
        throw std::runtime_error("Cannot open file");
    }
    return field;
}
