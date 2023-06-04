#include "Player.hpp"
#include <iostream>
// for fabs
#include <cmath>

int main(int argc, char **argv)
{
    // check if the player is correctly initialized
    Player player(5, 5);
    if(player.id() != 0){
        std::cout << "Test KO: wrong id" << std::endl;
        return 1;
    }

    if(fabs(player.speed() - 0.1f) > 0.0001){    // we use fabs because of float imprecision
        std::cout << "Test KO: wrong speed " << std::endl;
        return 1;
    }
    if(player.bombCapacity() != 1){
        std::cout << "Test KO: wrong bomb capacity" << std::endl;
        return 1;
    }
    if(player.bombRange() != 1){
        std::cout << "Test KO: wrong bomb range" << std::endl;
        return 1;
    }
    if(player.x() != 5 || player.y() != 5){
        std::cout << "Test KO: wrong position" << std::endl;
        return 1;
    }
    if(player.bombCount() != 0){
        std::cout << "Test KO: wrong bomb count" << std::endl;
        return 1;
    }


    // check setters
    player.bombCapacity() = 2;
    player.bombRange() = 3;
    player.speed() = 0.2;
    player.bombCount() ++;
    if(player.bombCapacity() != 2){
        std::cout << "Test KO: wrong bomb capacity" << std::endl;
        return 1;
    }
    if(player.bombRange() != 3){
        std::cout << "Test KO: wrong bomb range" << std::endl;
        return 1;
    }
    if(fabs(player.speed() - 0.2) > 0.0001){    // we use fabs because of float imprecision
        std::cout << "Test KO: wrong speed" << player.speed() << std::endl;
        return 1;
    }
    if(player.bombCount() != 1){
        std::cout << "Test KO: wrong bomb count" << std::endl;
        return 1;
    }


    // check id incrementation
    Player player2(5, 5);
    if(player2.id() != 1){
        std::cout << "Test KO: wrong id" << std::endl;
        return 1;
    }
    return 0;
}