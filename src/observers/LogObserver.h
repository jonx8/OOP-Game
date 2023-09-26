#include "Observer.h"
#include <vector>

class Logger;

class LogObserver : public Observer {
private:
    std::vector<Logger *> logList;

public:
    using Observer::Observer;

    ~LogObserver() override;

    void addLogger(Logger *logger);

    void removeLogger(Logger *logger);

    void update(const Message &msg) override;
};
