#include "Block.hpp"
#include "Terrain.hpp"
#include "Case.hpp"
#include <iostream>

Block::Block(const int& x, const int& y, const bool& isDestructible, PowerUp* powerUp) : AbstractGameElement(x, y)
{
    this->isDestructible_ = isDestructible;
    this->powerUp_ = powerUp;
}

void Block::destroy(){
    // put the power up on the case (if there is one)
    Terrain* terrain = Terrain::GetInstance();
    if(this->powerUp_ != nullptr){
        // normally the power up already has the right x and y
        Case* currCase = terrain->getCase(this->x(), this->y());
        // check if the case is not null
        if(currCase != nullptr){
            currCase->addElem(this->powerUp_);
        }
    }
    // remove the block from the case
    Case* currCase = terrain->getCase(this->x(), this->y());
    // check if the case is not null
    if(currCase != nullptr){
        currCase->suppElem(this);
    }
    // delete the block
    delete this;

}

void Block::display(SFMLRenderer& renderer){
    renderer.displayBlock(this);
}

std::ostream& operator<<(std::ostream& os, const Block& block){
    os << "Block: x=" << block.x() << ", y=" << block.y() << ", isDestructible=" << block.isDestructible_;
    return os;
}