#ifndef POWERUPDEATH_HPP
#define POWERUPDEATH_HPP
#include <vector>
#include "AbstractPowerUp.hpp"
#include <iostream>

class PowerUpDeath: public AbstractPowerUp
{

public:

    static const float SPEED_DECREASE;

    // constructor
    PowerUpDeath(const int& x, const int& y) : AbstractPowerUp(x,y) {};
    // destructor
    //~Bomb();
    void apply(Player* owner);


private:


};
#endif