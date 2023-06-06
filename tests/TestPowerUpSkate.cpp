#include "PowerUpSkate.hpp"
#include "Player.hpp"
#include <iostream>
#include <cmath>

int main(int argc, char **argv) {
    Player player(0,0);
    PowerUpSkate powerUpSkate(0,0);

    float before_speed = player.speed();
    powerUpSkate.apply(&player);

    // check if the player speed has changed (it should)
    if (fabs(player.speed() - (before_speed + PowerUpSkate::SPEED_INCREASE)) > 0.0001) {
        std::cout << "apply PowerupSkate on player with speed 0.2] KO - expected ";
        std::cout << before_speed + PowerUpSkate::SPEED_INCREASE << ", got " << player.speed() << std::endl;
        return 1;
    }
    return 0;
}