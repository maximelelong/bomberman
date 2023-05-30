#ifndef BOMB_HPP
#define BOMB_HPP
#include <vector>
#include "AbstractGameElement.hpp"

class Bomb: public AbstractGameElement
{

public:

    // constructor
    Bomb(const int& x, const int& y, Player* owner);
    // destructor
    //~Bomb();

    // overriden display from Displayable
    void display(SFMLRenderer& renderer) override;
    // overriden update from AbstractGameElement
    void update(std::vector<sf::Event>& userInputs) override;

private:
    
    int id_;
    int timer_;
    Player* owner_;

    void explode();

};
#endif