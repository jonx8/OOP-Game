#pragma once
#include <string>

class Message;
class Observer
{
private:
    std::string name;
public:
    explicit Observer(const char *name);
    virtual ~Observer() = 0;
    virtual void update(const Message &msg) = 0;
    [[nodiscard]] std::string getName() const;
};
