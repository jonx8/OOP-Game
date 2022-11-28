#include "loggers/FileLogger.h"
#include "loggers/ConsoleLogger.h"
#include "eventsRegister/EventsRegister.h"
#include "views/PlayerView.h"
#include "views/FieldView.h"
#include "controllers/Game.h"
#include "fieldGenerators/generationRules/EventsPosRule.h"
#include "fieldGenerators/generationRules/FieldSizeRule.h"
#include "fieldGenerators/generationRules/PlayerPosRule.h"
#include "fieldGenerators/generationRules/ObjectPosRule.h"
#include "fieldGenerators/generationRules/MainBuildingRule.h"
#include "fieldGenerators/FieldGenerator.h"
#include "observers/LogObserver.h"
#include "controllers/readers/ConsoleReader.h"
#include "models/Cell.h"

int main()
{
    const char CONTROL_SETTINGS_FILE[] = "controlSettings.conf";
    const char LOG_FILE_NAME[] = "gamelogs.log";

    auto *obs = new LogObserver("GameObs");

    // Player initialization
    auto *player = new Player;
    // player->addObserver(obs);

    // Reader initialization
    auto *reader = new ConsoleReader;
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
        auto *console_logger = new ConsoleLogger;
        console_logger->setLevel(static_cast<Message::MSG_TYPE>(log_params.second));
        obs->addLogger(console_logger);
    }

    // File logger initialization
    if (log_params.first == FILE_LOG || log_params.first == CONSOLE_FILE_LOG)
    {
        auto *file_logger = new FileLogger(LOG_FILE_NAME);
        file_logger->setLevel(static_cast<Message::MSG_TYPE>(log_params.second));
        obs->addLogger(file_logger);
    }

    // Events Register initialization
    EventsRegister &evReg = EventsRegister::getReg();
    evReg.addEventObserver(obs);

    using StdHutGen = FieldGenerator<FieldSizeRule<20, 25>,
                                     MainBuildingRule<HUT, EventType::VICTORY_EVENT, 10, 10>,
                                     MainBuildingRule<HUT, EventType::EXPLODE_EVENT, 15, 15>,
                                     PlayerPosRule<10, 10>,
                                     EventsPosRule<1, EventType::FLOOD_EVENT>,
                                     EventsPosRule<10, EventType::ARMOR_EVENT>,
                                     EventsPosRule<2, EventType::HEAL_EVENT>,
                                     ObjectsPosRule<5, Cell::Objects::WALL>,
                                     ObjectsPosRule<20, Cell::Objects::GRASS>,
                                     ObjectsPosRule<30, Cell::Objects::WATER>,
                                     EventsPosRule<2, EventType::EXPLODE_EVENT>,
                                     EventsPosRule<2, EventType::SPRING_EVENT>>;

    using StdLabirintGen = FieldGenerator<FieldSizeRule<20, 25>,
                                          MainBuildingRule<LABIRINT, EventType::VICTORY_EVENT, 10, 10>,
                                          PlayerPosRule<10, 10>,
                                          EventsPosRule<1, EventType::FLOOD_EVENT>,
                                          EventsPosRule<10, EventType::ARMOR_EVENT>,
                                          EventsPosRule<2, EventType::HEAL_EVENT>,
                                          ObjectsPosRule<5, Cell::Objects::WALL>,
                                          ObjectsPosRule<20, Cell::Objects::GRASS>,
                                          ObjectsPosRule<30, Cell::Objects::WATER>,
                                          EventsPosRule<2, EventType::EXPLODE_EVENT>,
                                          EventsPosRule<2, EventType::SPRING_EVENT>>;
    StdHutGen generator;
    Field &field = generator.getField(player, obs);

    // Views initialization
    PlayerView playerStatus(player, 15);
    FieldView fieldViewer(field);
    fieldViewer.setBorderChar('@');

    auto *controller = new Controller(fieldViewer, playerStatus, field, player);
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
    delete obs;
    return 0;
}
