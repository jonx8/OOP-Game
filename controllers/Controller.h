#pragma once

#include <memory>
#include "../models/Player.h"
#include "../views/FieldView.h"
#include "../views/PlayerView.h"
#include "../fieldGenerators/GameCreator.h"


class Player;

class Controller {
private:
    FieldView fieldView;
    PlayerView playerStatus;
    GameCreator gameCreator;
    std::unique_ptr<Player> player;
    Field* gamefield;
    Observer *observer;
    bool running;
public:
    explicit Controller(Observer *obs = nullptr);

    void startGame();

    void resetGame();

    void exitGame();

    void setObserver(Observer *obs);

    void showField() const;

    void showPlayerStatus() const;

    void movePlayer(Field::Directions direction);

    bool isDefeat();

    [[nodiscard]] bool isVictory() const;

    [[nodiscard]] bool isRunning() const;
};
