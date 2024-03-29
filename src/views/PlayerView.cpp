#include "PlayerView.h"
#include <iostream>

PlayerView::PlayerView(Player *player, uint scaleLen) : player(player), scaleLen(scaleLen) {}

void PlayerView::setPlayer(Player *new_player) { player = new_player; }

void PlayerView::showHealth() const {
    std::cout << "Health: ";
    scalePrint(player->getHealth(), player->getHealthMax());
}

void PlayerView::showStamina() const {
    std::cout << "Stamina: ";
    scalePrint(player->getStamina(), player->getStaminaMax());
}

void PlayerView::showArmor() const {
    std::cout << "Armor: ";
    if (player->hasArmor()) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

void PlayerView::scalePrint(uint curr, uint max) const {
    double scalePerCent = static_cast<double>(curr) / static_cast<double>(max);
    double currLen = scaleLen * scalePerCent;
    std::cout << '[';

    for (auto i = 0; i < currLen; i++) {
        std::cout << '#';
    }

    for (auto i = 0; i < scaleLen - currLen; i++) {
        std::cout << ' ';
    }
    std::cout << "] - [" << curr << "/" << max << "] - " << scalePerCent * 100 << '%' << std::endl;
}
