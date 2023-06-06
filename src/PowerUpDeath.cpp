#include "PowerUpDeath.hpp"
#include "Player.hpp"

const float PowerUpDeath::SPEED_DECREASE = 0.05;

void PowerUpDeath::apply(Player* owner)
{   
    if(owner->speed() - SPEED_DECREASE >=  Player::DEFAULT_SPEED)
    {
        owner->speed() -= SPEED_DECREASE;
    }
}