#include "Player.h"

Player::Player() : health(100), HEALTH_MAX(100), damage(15), stamina(100), STAMINA_MAX(100), winner(false), armor(false)
{
}

Player::Player(int healthMax, int damage, int staminaMax) : health(healthMax), HEALTH_MAX(healthMax), damage(damage), stamina(staminaMax), STAMINA_MAX(staminaMax), winner(false) {}

Player::~Player() {}

int Player::getHealth() const { return health; }
int Player::getHealthMax() const { return HEALTH_MAX; }
int Player::getDamage() const { return damage; }
int Player::getStamina() const { return stamina; }
int Player::getStaminaMax() const { return STAMINA_MAX; }
bool Player::isDead()
{
    if (health == 0)
    {
        notify(Message("Player defeat", Message::INFO));
    }
    return !health;
}
bool Player::isWin() const { return winner; }
bool Player::hasArmor() const { return armor; }

void Player::setStamina(int stamina) { this->stamina = stamina; }
void Player::setDamage(int damage) { this->damage = damage; }
void Player::win()
{
    notify(Message("Player wins", Message::INFO));
    winner = true;
}
void Player::setArmor(bool value)
{
    armor = value;
    notify(Message("Player take armor", Message::INFO));
}
void Player::changeHealth(int value)
{
    health += value;
    if (health < 0)
    {
        health = 0;
    }

    if (health > HEALTH_MAX)
    {
        health = HEALTH_MAX;
    }

    notify(Message("Player health was changed to " + std::to_string(health), Message::INFO));
}

void Player::setHealth(int health)
{
    if (health >= 0 && health <= HEALTH_MAX)
    {
        this->health = health;
    }
}

void Player::changeStamina(int value)
{
    stamina += value;
    if (stamina < 0)
    {
        stamina = 0;
    }

    if (stamina > STAMINA_MAX)
    {
        stamina = STAMINA_MAX;
    }
    
}
