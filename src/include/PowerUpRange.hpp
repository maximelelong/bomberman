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
    /** @brief applique le power up au joueur qui le trouve*/
    void apply(Player* owner);

};
#endif