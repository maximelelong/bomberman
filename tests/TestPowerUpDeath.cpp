#include "PowerUpDeath.hpp"
#include "Player.hpp"
#include <iostream>
#include <cmath> // for std::fabs

int main(int argc, char **argv)
{
    Player player(0,0);

    PowerUpDeath powerUpDeath(0,0);
    powerUpDeath.apply(&player);
    
    // check if the player speed has changed (it should not)
    if (fabs(player.speed() - Player::DEFAULT_SPEED) > 0.0001) {
        std::cout << "[apply PowerupDeath on default player values] KO - expected 0.1, got " << player.speed() << std::endl;
        return 1;
    }

    player.speed() = 0.2;
    powerUpDeath.apply(&player);
    // check if the player speed has changed (it should)
    if (fabs(0.2 - player.speed() - PowerUpDeath::SPEED_DECREASE) > 0.0001) {
        std::cout << "apply PowerupDeath on player with speed 0.2] KO - expected 0.1, got " << player.speed() << std::endl;
        return 1;
    }

    return 0;   
}