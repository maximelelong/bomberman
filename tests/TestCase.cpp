#include "Case.hpp"
#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Block.hpp"

int main(int argc, char **argv)
{

    std::cout << "=============Test Case============" << std::endl;

    Case c(5, 5);

    // test basic getters
    std::cout << "=============Test Case::x()============" << std::endl;
    if (c.x() != 5){
        std::cout << "Test Case::x() KO" << std::endl;
        return 1;
    }
    std::cout << "=============Test Case::y()============" << std::endl;
    if (c.y() != 5){
        std::cout << "Test Case::y() KO" << std::endl;
        return 1;
    }
    
    // test addElem
    std::cout << "=============Test Case::addElem()============" << std::endl;
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
    std::cout << "=============Test Case::suppElem()============" << std::endl;
    c.suppElem(&player);
    if (c.gameElements().size() != 0){
        std::cout << "Test Case::suppElem() KO" << std::endl;
        return 1;
    }

    // test contains functions

    std::cout << "=============Test Case::containsBomb()============" << std::endl;
    if (c.containsBomb()){
        std::cout << "Test Case::containsBomb() KO" << std::endl;
        return 1;
    }
    std::cout << "=============Test Case::containsPlayer()============" << std::endl;
    if (c.containsPlayer()){
        std::cout << "Test Case::containsPlayer() KO" << std::endl;
        return 1;
    }
    std::cout << "=============Test Case::containsIndestructibleBlock()============" << std::endl;
    if (c.containsIndestructibleBlock()){
        std::cout << "Test Case::containsIndestructibleBlock() KO" << std::endl;
        return 1;
    }
    std::cout << "=============Test Case::containsDestructibleBlock()============" << std::endl;
    if (c.containsDestructibleBlock()){
        std::cout << "Test Case::containsDestructibleBlock() KO" << std::endl;
        return 1;
    }

    std::cout << "=============End Test Case============" << std::endl;


    return 0;
}