#ifndef POWERUPRANGE_HPP
#define POWERUPRANGE_HPP
#include <vector>
#include "AbstractPowerUp.hpp"
#include <iostream>

class PowerUpRange: public AbstractPowerUp
{

public:

    // constructor
    PowerUpRange(const int& x, const int& y) : AbstractPowerUp(x,y) {};
    // destructor
    //~Bomb();
    void apply(Player* owner);

};
#endif