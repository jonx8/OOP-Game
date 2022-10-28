#pragma once
#include <string>

class Message;
class Observer
{
private:
    std::string name;
public:
    Observer(const char *name);
    virtual ~Observer() = 0;
    virtual void update(const Message &msg) = 0;
    void setName(const char *name);
    std::string getName() const;
};
