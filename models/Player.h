#pragma once
#include <iostream>

class Player
{
private:
    int health;
    const int HEALTH_MAX;
    int damage;
    int stamina;
    const int STAMINA_MAX;
    bool winner;
    std::pair<uint, uint> coords; // first - x, second - y

public:
    Player();
    Player(int healthMax, int damage, int staminaMax);
    ~Player();
    int getHealth() const;
    int getDamage() const;
    int getStamina() const;
    int getHealthMax() const;
    int getStaminaMax() const;
    std::pair<uint, uint> getCoords() const;
    void win();
    void setCoords(uint CoordX, uint CoordY);
    void setDamage(int damage);
    void setStamina(int stamina);
    void changeHealth(int value);
    void setHealth(int health);
    bool isDead() const;
    bool isWin() const;
};