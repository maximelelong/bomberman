#ifndef POWERUPRANGE_HPP
#define POWERUPRANGE_HPP
#include <vector>
#include "PowerUp.hpp"
#include <iostream>

class Player;

class PowerUpRange: public PowerUp
{

public:

    // constructor
    PowerUpRange(const int& x, const int& y) : PowerUp(x,y) {};
    // destructor
    //~Bomb();

    // overriden display from Displayable
    void display(SFMLRenderer& renderer);
    // overriden update from AbstractGameElement

private:

    void Apply(Player* owner);

};
#endif