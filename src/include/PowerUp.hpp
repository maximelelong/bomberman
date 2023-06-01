#ifndef POWERUP_HPP
#define POWERUP_HPP

#include "AbstractGameElement.hpp"

class PowerUp : public AbstractGameElement
{
public:
    PowerUp(const int& x, const int& y);
    // ~PowerUp();

    void display(SFMLRenderer& renderer) override;
    void update(std::vector<sf::Event>& userInputs);

private:

};

#endif