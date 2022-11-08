#include "loggers/FileLogger.h"
#include "loggers/ConsoleLogger.h"
#include "eventsRegister/EventsRegister.h"
#include "views/PlayerView.h"
#include "views/FieldView.h"
#include "models/Field.h"
#include "observers/LogObserver.h"
#include "controllers/readers/ConsoleReader.h"
#include "controllers/Game.h"
#include "models/Cell.h"

int main()
{
    const char CONTROL_SETTINGS_FILE[] = "controlSettings.conf";
    const char LOG_FILE_NAME[] = "gamelogs.log";

    LogObserver *obs = new LogObserver("GameObs");

    // Player initialization
    Player *player = new Player;
    player->addObserver(obs);

    // Reader initialization
    ConsoleReader *reader = new ConsoleReader;
    reader->addObserver(obs);

    // Loggers initialization
    enum logMethod
    {
        NO_LOG = 1,
        CONSOLE_LOG,
        FILE_LOG,
        CONSOLE_FILE_LOG,
    };
    // First - method of logging, second - level of logging
    std::pair<int, int> log_params = reader->readLogParams();

    // Console logger initialization
    if (log_params.first == CONSOLE_LOG || log_params.first == CONSOLE_FILE_LOG)
    {
        ConsoleLogger *console_logger = new ConsoleLogger;
        console_logger->setLevel(static_cast<Message::MSG_TYPE>(log_params.second));
        obs->addLogger(console_logger);
    }

    // File logger initialization
    if (log_params.first == FILE_LOG || log_params.first == CONSOLE_FILE_LOG)
    {
        FileLogger *file_logger = new FileLogger(LOG_FILE_NAME);
        file_logger->setLevel(static_cast<Message::MSG_TYPE>(log_params.second));
        obs->addLogger(file_logger);
    }

    // Events Register initialization
    EventsRegister *evReg = new EventsRegister(obs);

    // Field initializing
    std::pair<int, int> sizes = reader->readFieldSize();
    Field field(sizes.first, sizes.second, player);
    field.addObserver(obs);
    field.setEventRegister(evReg);
    field.stdFieldGen();
    field.setPlayerCoord(0, 0);

    // Views initialization
    PlayerView playerStatus(player, 15);
    FieldView fieldViewer(field);
    fieldViewer.setBorderChar('@');

    Controller *controller = new Controller(fieldViewer, playerStatus, field, player);
    controller->setObserver(obs);
    if (reader->ImportFileConf(CONTROL_SETTINGS_FILE))
    {
        Game game(controller, reader);
        game.start();
    }
    else
    {
        std::cout << "Problem with file " << CONTROL_SETTINGS_FILE << ". Check logs!" << std::endl;
    }

    delete controller;
    delete reader;
    delete evReg;
    delete obs;
    return 0;
}
