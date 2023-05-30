#include "Bomb.hpp"

Bomb::Bomb(const int& x, const int& y, Player* owner) : AbstractGameElement(x, y)
{
    this->timer_ = 3;
    this->owner_ = owner;
}

void Bomb::display(SFMLRenderer& renderer){
    renderer.displayBomb(this);
}

void Bomb::update(std::vector<sf::Event>& userInputs){
    // refresh the timer
    this->timer_ -= 1;
    if (this->timer_ == 0){
        this->explode();
    }
}

void Bomb::explode() {
    // TODO: implement this function
}