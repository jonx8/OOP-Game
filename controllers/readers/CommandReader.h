#pragma once
#include <functional>
#include <unordered_map>
#include "../../observable/Observable.h"

class ICommand;
class CommandReader : public Observable
{
protected:
    std::unordered_map<std::string, ICommand *, std::hash<std::string>> commands;
    bool is_default_settings;
public:
    CommandReader();
    virtual ~CommandReader() = 0;
    virtual ICommand *readcmd() = 0;
    virtual std::pair<int, int> readFieldSize() = 0;
    virtual std::pair<int, int> readLogParams() = 0;
    virtual void loadDefaultSettings();
    virtual bool ImportFileConf(const char *filename);
};