#pragma once
#include "../models/Player.h"

class PlayerView
{
private:
    Player *player;
    uint scaleLen;
    void scalePrint(uint curr, uint max) const;

public:
    explicit PlayerView(Player *player, uint scaleLen = 15);
    void setPlayer(Player *);
    void showHealth() const;
    void showStamina() const;
    void showDamage() const;
    void showArmor() const;
};
