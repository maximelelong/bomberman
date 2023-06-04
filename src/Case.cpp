#include <iostream>
#include "Case.hpp"
#include "Block.hpp"
#include "Bomb.hpp"
#include "Player.hpp"
#include "PowerUpSkate.hpp"
#include "PowerUpDeath.hpp"
#include "PowerUpBomb.hpp"


Case::Case(const uint x, const uint y)
{
    x_ = x;
    y_ = y;
}


void Case::suppElem(AbstractGameElement* elem){    //parcourt la liste, et si l'element pointé par l'iterateur a le meme serial que l'element a supprimer, le supprime
    for (int i = 0; i < this->gameElements_.size(); i++){
        if (gameElements_[i]->serial() == elem->serial()){
            gameElements_.erase(gameElements_.begin()+i);
            break;
        }
    }       
}

void Case::addElem(AbstractGameElement* elem){     //ajoute un element à la liste de la case
    this->gameElements_.push_back(elem);
    // std::cout << "case (" << this->x() << "," << this->y()  << ") Element ajouté (serial : " << elem->serial() << ")"  << std::endl;
}

void Case::display(SFMLRenderer& renderer){

    for (int i = 0; i < this->gameElements_.size(); i++){
        this->gameElements_[i]->display(renderer);
    }
}

void Case::update(std::vector<sf::Keyboard::Key>& userInputs){
    for (int i = 0; i < this->gameElements_.size(); i++){
        this->gameElements_[i]->update(userInputs);
    }
}

bool Case::containsIndestructibleBlock(){
    for (int i = 0; i < this->gameElements_.size(); i++){
        AbstractGameElement* elem = this->gameElements_[i];
        if (typeid(*elem) == typeid(Block)){
            // check if the block is indestructible
            Block* block = dynamic_cast<Block*>(elem);
            if (!block->isDestructible()){
                return true;
            }
        }
    }
    return false;
}

bool Case::containsDestructibleBlock(){
    for (int i = 0; i < this->gameElements_.size(); i++){
        AbstractGameElement* elem = this->gameElements_[i];
        if (typeid(*elem) == typeid(Block)){
            // check if the block is indestructible
            Block* block = dynamic_cast<Block*>(elem);
            if (block->isDestructible()){
                return true;
            }
        }
    }
    return false;
}

bool Case::containsBomb(){
    for (int i = 0; i < this->gameElements_.size(); i++){
        AbstractGameElement* elem = this->gameElements_[i];
        if (typeid(*elem) == typeid(Bomb)){
            return true;
        }
    }
    return false;
}

bool Case::containsPlayer(){
    for (int i = 0; i < this->gameElements_.size(); i++){
        AbstractGameElement* elem = this->gameElements_[i];
        if (typeid(*elem) == typeid(Player)){
            return true;
        }
    }
    return false;
}

bool Case::applyExplosion(){
    bool hasBeenDestroyed = false;
    for (int i = 0; i < this->gameElements_.size(); i++){
        AbstractGameElement* elem = this->gameElements_[i];
        
        if (typeid(*elem) == typeid(Block)){
            // check if the block is destructible, if so, destroy it
            Block* block = dynamic_cast<Block*>(elem);
            if (block->isDestructible()){
                block->destroy();
            }
        }
        else if (typeid(*elem) == typeid(Player)){
            // check if the player is dead, if so, destroy it
            Player* player = dynamic_cast<Player*>(elem);
        }
    }
    return hasBeenDestroyed;
}

bool Case::isPowerUp(int nb){
    AbstractGameElement* elem = this->gameElements_[nb];
    if ((typeid(*elem) == typeid(PowerUpSkate))||(typeid(*elem) == typeid(PowerUpDeath))||((typeid(*elem) == typeid(PowerUpBomb)))){
        return true;
    }
    return false;
}

PowerUp* Case::getPowerUp(int nb)
{
        AbstractGameElement* elem = this->gameElements_[nb];
        PowerUp* PU = dynamic_cast<PowerUp*>(elem);
        return PU;
}