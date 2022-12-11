#pragma once

#include <memory>
#include "../views/FieldView.h"
#include "../views/PlayerView.h"
#include "../fieldGenerators/LevelController.h"

class Player;

class Controller {
private:
    FieldView fieldView;
    PlayerView playerStatus;
    LevelController levelCreator;
    std::unique_ptr<Player> player;
    Field *gamefield;
    Observer *observer;
    bool running;

public:
    explicit Controller(Observer *obs = nullptr);

    void startGame(FieldType type);

    void resetGame();

    void exitGame();

    void setObserver(Observer *obs);

    void showField() const;

    void showPlayerStatus() const;

    void movePlayer(Directions direction);

    bool isDefeat();

    void saveGame() const;

    void loadGame();

    [[nodiscard]] bool isVictory() const;

    [[nodiscard]] bool isRunning() const;
};
