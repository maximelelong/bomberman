#ifndef POWERUPSKATE_HPP
#define POWERUPSKATE_HPP
#include <vector>
#include "AbstractPowerUp.hpp"
#include <iostream>

class PowerUpSkate: public AbstractPowerUp
{

public:
    static const float SPEED_INCREASE;
    // constructor
    PowerUpSkate(const int& x, const int& y) : AbstractPowerUp(x,y) {};
    // destructor
    //~Bomb();
    /** @brief applique le power up au joueur qui le trouve*/
    void apply(Player* owner);
};
#endif