#ifndef POWERUPBOMB_HPP
#define POWERUPBOMB_HPP
#include <vector>
#include "PowerUp.hpp"
#include <iostream>

class Player;

class PowerUpBomb: public PowerUp
{

public:

    // constructor
    PowerUpBomb(const int& x, const int& y) : PowerUp(x,y) {};
    // destructor
    //~Bomb();

    // overriden display from Displayable
    void display(SFMLRenderer& renderer);
    // overriden update from AbstractGameElement

private:

    void Apply(Player* owner);

};
#endif