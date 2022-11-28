#pragma once
#include "../observable/Observable.h"

using uint = unsigned int;
class Player : public Observable
{
private:
    int health;
    const int HEALTH_MAX;
    int damage;
    int stamina;
    const int STAMINA_MAX;
    bool winner;
    bool armor{};

public:
    Player();
    ~Player() override;
    [[nodiscard]] int getHealth() const;
    [[nodiscard]] int getDamage() const;
    [[nodiscard]] int getStamina() const;
    [[nodiscard]] int getHealthMax() const;
    [[nodiscard]] int getStaminaMax() const;
    [[nodiscard]] bool isWin() const;
    [[nodiscard]] bool hasArmor() const;
    bool isDead();
    void win();
    void setDamage(int damage);
    void setStamina(int stamina);
    void setArmor(bool value);
    void changeHealth(int value);
    void changeStamina(int value);
    void setHealth(int health);

};