#include "PowerUpRange.hpp"
#include "Player.hpp"
#include <iostream>

int main(int argc, char **argv) {
    Player player(0,0);
    PowerUpRange powerUpRange(0,0);

    int before_bomRange = player.bombRange();
    powerUpRange.apply(&player);
    
    // check if the player range has changed (it should)
    if (player.bombRange() != before_bomRange + 1) {
        std::cout << "apply PowerupRange on player with range 2] KO - expected " << before_bomRange << ", got " << player.bombRange() << std::endl;
        return 1;
    }

    return 0;
}