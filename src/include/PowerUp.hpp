#ifndef POWERUP_HPP
#define POWERUP_HPP

#include "AbstractGameElement.hpp"
#include "Block.hpp"
#include "Terrain.hpp"
#include <iostream>

class Player;

class PowerUp : public AbstractGameElement
{
public:
    PowerUp(const int& x, const int& y);

    // ~PowerUp();
    virtual void Apply(Player* owner)=0;

private:

};

#endif