#include "loggers/FileLogger.h"
#include "loggers/ConsoleLogger.h"
#include "eventsRegister/EventsRegister.h"
#include "controllers/Game.h"
#include "observers/LogObserver.h"
#include "controllers/readers/ConsoleReader.h"

int main() {
    const char CONTROL_SETTINGS_FILE[] = "controlSettings.conf";
    const char LOG_FILE_NAME[] = "gamelogs.log";


    LogObserver obs("GameObs");

    // Reader initialization
    ConsoleReader reader;
    reader.addObserver(&obs);

    // Loggers initialization
    enum logMethod {
        NO_LOG = 1,
        CONSOLE_LOG,
        FILE_LOG,
        CONSOLE_FILE_LOG,
    };
    // First - method of logging, second - level of logging
    auto [logging_type, logging_lvl] = reader.readLogParams();

    // Console logger initialization
    if (logging_type == CONSOLE_LOG || logging_type == CONSOLE_FILE_LOG) {
        auto console_logger = new ConsoleLogger;
        console_logger->setLevel(static_cast<Message::MSG_TYPE>(logging_lvl));
        obs.addLogger(console_logger);
    }

    // File logger initialization
    if (logging_type == FILE_LOG || logging_type == CONSOLE_FILE_LOG) {
        auto file_logger = new FileLogger(LOG_FILE_NAME);
        file_logger->setLevel(static_cast<Message::MSG_TYPE>(logging_lvl));
        obs.addLogger(file_logger);
    }

    // Events Register initialization
    EventsRegister &evReg = EventsRegister::getReg();
    evReg.addEventObserver(&obs);

    Controller controller(&obs);

    if (reader.ImportFileConf(CONTROL_SETTINGS_FILE)) {
        Game game(controller, reader);
        game.start();
    } else {
        std::cout << "Problem with file " << CONTROL_SETTINGS_FILE << ". Check logs!" << std::endl;
    }

    return 0;
}
