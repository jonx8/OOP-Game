#pragma once
#include <string>
#include <vector>
#include "../messages/Message.h"
#include "../loggers/Logger.h"
class Observer
{
private:
    std::string name;
    std::vector<Logger *> logList;

public:
    Observer(const char* name);
    ~Observer();
    void update(const Message &msg);
    void addLogger(Logger *logger);
    void removeLogger(Logger *logger);
    void setName(const char *name);
    std::string getName() const;
};
