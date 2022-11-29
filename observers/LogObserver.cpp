#include "LogObserver.h"
#include "../loggers/Logger.h"

LogObserver::~LogObserver() {
    for (auto i: logList) {
        delete i;
    }
}

void LogObserver::update(const Message &msg) {
    for (auto i: logList) {
        i->log(msg);
    }
}

void LogObserver::addLogger(Logger *logger) {
    logList.emplace_back(logger);
}

void LogObserver::removeLogger(Logger *logger) {
    for (size_t i = 0; i < logList.size(); i++) {
        if (logList[i] == logger) {
            logList.erase(logList.begin() + i);
            break;
        }
    }
}