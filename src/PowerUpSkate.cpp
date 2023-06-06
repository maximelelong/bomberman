#include "PowerUpSkate.hpp"
#include "Player.hpp"

const float PowerUpSkate::SPEED_INCREASE = 0.05;
void PowerUpSkate::apply(Player* owner)
{
    if(owner->speed()+SPEED_INCREASE < Player::MAX_SPEED)
    {
        owner->speed() += SPEED_INCREASE;
    }
}