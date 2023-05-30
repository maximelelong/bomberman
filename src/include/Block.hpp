#ifndef BLOCK_HPP
#define BLOCK_HPP
#include <vector>
#include "AbstractGameElement.hpp"

class Block : public AbstractGameElement
{
public:
    // constructor
    Block(const int& x, const int& y, const bool& isDestructible);
    // destructor
    //~Block();

    // overriden display from Displayable
    void display(SFMLRenderer& renderer) override;
    void update(std::vector<sf::Event>& userInputs);

    // accessors
    const bool& isDestructible() const   { return this->isDestructible_;}

private:
    
    bool isDestructible_;

    
};

#endif