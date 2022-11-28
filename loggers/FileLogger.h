#include "Logger.h"
#include <fstream>

class Message;

class FileLogger : public Logger
{
private:
    std::string filename;
    std::ofstream logfile;

public:
    explicit FileLogger(const char *filename);
    ~FileLogger() override;
    void log(const Message &msg) override;
};
