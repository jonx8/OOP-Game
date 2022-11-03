#pragma once
#include "../../observable/Observable.h"
#include <unordered_map>

class CommandReader : public Observable
{
protected:
    std::unordered_map<std::string, std::string> commands;

public:
    virtual ~CommandReader() = 0;
    virtual std::string readcmd() = 0;
    virtual std::pair<int, int> readFieldSize() = 0;
    virtual std::pair<int, int> readLogParams() = 0;
    bool ImportFileConf(const char *filename);
};