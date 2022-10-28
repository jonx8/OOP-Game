#pragma once
#include <iostream>
#include "../observable/Observable.h"
class CommandReader : public Observable
{
private:
    std::pair <int, int> sizes;
    std::string currentCmd;

public:
    CommandReader();
    void readcmd();
    void readFieldSize();
    std::pair<int, int> readLogParams() const;
    std::pair <int, int> getFieldSize() const;
    std::string getCurrentCmd();
};