#include "PowerUpBomb.hpp"
#include "Player.hpp"
#include <iostream>

int main(int argc, char **argv) {
    Player player(0,0);
    PowerUpBomb powerUpBomb(0,0);

    int before_bomCapacity = player.bombCapacity();
    powerUpBomb.apply(&player);
    
    // check if the player bomb number has changed (it should)
    if (player.bombCapacity() != before_bomCapacity + 1) {
        std::cout << "apply PowerupBomb on player with bomb number 2] KO - expected " << before_bomCapacity << ", got " << player.bombCapacity() << std::endl;
        return 1;
    }


}