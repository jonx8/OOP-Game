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
    bool armor;

public:
    Player();
    Player(int healthMax, int damage, int staminaMax);
    ~Player();
    int getHealth() const;
    int getDamage() const;
    int getStamina() const;
    int getHealthMax() const;
    int getStaminaMax() const;
    void win();
    void setDamage(int damage);
    void setStamina(int stamina);
    void setArmor(bool value);
    void changeHealth(int value);
    void changeStamina(int value);
    void setHealth(int health);
    bool isDead() const;
    bool isWin() const;
    bool hasArmor() const;
    void notify(const Message&) override;
};