#include "Block.hpp"

Block::Block(const int& x, const int& y, const bool& isDestructible) : AbstractGameElement(x, y)
{
    this->isDestructible_ = isDestructible;
}

void Block::display(SFMLRenderer& renderer){
    renderer.displayBlock(this);
}

void Block::update(std::vector<sf::Event>& userInputs){
    // Nothing to do
}