#include "Case.hpp"
#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Block.hpp"

int main(int argc, char **argv)
{

    Case c(5, 5);

    // test basic getters
    if (c.x() != 5){
        std::cout << "Test Case::x() KO" << std::endl;
        return 1;
    }
    if (c.y() != 5){
        std::cout << "Test Case::y() KO" << std::endl;
        return 1;
    }
    
    // test addElem
    Player player(5, 5);
    c.addElem(&player);

    if (c.gameElements().size() != 1){
        std::cout << "Test Case::addElem() KO" << std::endl;
        return 1;
    }
    if (c.gameElements()[0] != &player){
        std::cout << "Test Case::addElem() KO" << std::endl;
        return 1;
    }

    // test suppElem
    c.suppElem(&player);
    if (c.gameElements().size() != 0){
        std::cout << "Test Case::suppElem() KO" << std::endl;
        return 1;
    }

    // test contains functions

    if (c.containsBomb()){
        std::cout << "Test Case::containsBomb() KO" << std::endl;
        return 1;
    }
    if (c.containsPlayer()){
        std::cout << "Test Case::containsPlayer() KO" << std::endl;
        return 1;
    }
    if (c.containsIndestructibleBlock()){
        std::cout << "Test Case::containsIndestructibleBlock() KO" << std::endl;
        return 1;
    }
    if (c.containsDestructibleBlock()){
        std::cout << "Test Case::containsDestructibleBlock() KO" << std::endl;
        return 1;
    }

    return 0;
}