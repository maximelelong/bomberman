#include "Bomb.hpp"
#include "Player.hpp"
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    Player player(5, 5);

    // start the timer of the bomb
    sf::Clock timer;
    Bomb bomb(5, 5, &player);

    // getters before explosion
    if (bomb.owner() != &player){
        std::cout << "Test Bomb::owner() before explosion KO" << std::endl;
        return 1;
    }
    if (bomb.exploding() != false){
        std::cout << "Test Bomb::exploding() before explosion KO" << std::endl;
        return 1;
    }
    if (bomb.affectedCases().size() != 0){
        std::cout << "Test Bomb::affectedCases() before explosion KO" << std::endl;
        return 1;
    }

    // wait for the bomb timer to reach the explosion trigger time
    sf::Time tolerance = sf::milliseconds(100);
    sf::sleep(Bomb::EXPLOSION_TRIGGER_TIME - timer.getElapsedTime() + tolerance);
    // update the bomb
    std::vector<sf::Keyboard::Key> emptyUserInputs;
    bomb.update(emptyUserInputs);

    // getters after explosion
    if (bomb.owner() != &player){
        std::cout << "Test Bomb::owner() after explosion KO" << std::endl;
        return 1;
    }
    if (bomb.exploding() != true){
        std::cout << "Test Bomb::exploding() after explosion KO" << std::endl;
        return 1;
    }
    if (bomb.affectedCases().size() == 0){
        std::cout << "Test Bomb::affectedCases() after explosion KO" << std::endl;
        return 1;
    }

    return 0;
}