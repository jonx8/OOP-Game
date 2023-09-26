#pragma once

template<typename T>
class Serializator {
public:
    virtual ~Serializator() = 0;

    virtual void serialize(const char *filename, const T &) = 0;

    virtual void deserialize(const char *filename) = 0;
};

