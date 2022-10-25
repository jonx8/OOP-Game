#include "Logger.h"
#include <fstream>

class Message;

class FileLogger : public Logger
{
private:
    std::ostream logfile;
public:
    FileLogger(const char* filename);
    ~FileLogger();
    void log(Message& msg) override;
};
