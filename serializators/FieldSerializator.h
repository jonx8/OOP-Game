#pragma once

#include <string>

class Field;

class FieldSerializator {
public:
    static bool serialize(const std::string &filename, Field *field);

    static Field deserialize(const std::string &filename);
};

