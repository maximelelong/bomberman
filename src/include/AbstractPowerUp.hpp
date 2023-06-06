#ifndef POWERUP_HPP
#define POWERUP_HPP

#include "AbstractGameElement.hpp"
#include <iostream>

class Player;

class AbstractPowerUp : public AbstractGameElement
{
public:
    AbstractPowerUp(const int& x, const int& y);

    // ~AbstractPowerUp();
    virtual void apply(Player* owner)=0;

    // override display method
    void display(SFMLRenderer& renderer) override;

private:

};

#endif