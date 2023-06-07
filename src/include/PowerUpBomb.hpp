#ifndef POWERUPBOMB_HPP
#define POWERUPBOMB_HPP
#include <vector>
#include "AbstractPowerUp.hpp"
#include <iostream>


class PowerUpBomb: public AbstractPowerUp
{

public:

    // constructor
    PowerUpBomb(const int& x, const int& y) : AbstractPowerUp(x,y) {};
    // destructor
    //~Bomb();
    /** @brief applique le power up au joueur qui le trouve*/
    void apply(Player* owner) override;
};
#endif