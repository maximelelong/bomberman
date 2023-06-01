#include "Bomb.hpp"
#include "SFMLRenderer.hpp"
#include "Terrain.hpp"
#include "Player.hpp"
#include "Block.hpp"
#include <iostream>


const sf::Time Bomb::EXPLOSION_TRIGGER_TIME = sf::seconds(3);
const sf::Time Bomb::EXPLOSION_DURATION = sf::seconds(1);

Bomb::Bomb(const int& x, const int& y, Player* owner) : AbstractGameElement(x, y)
{
    this->timer_.restart();
    this->exploding_ = false;
    this->owner_ = owner;
    this->affectedCases_ = std::vector<Case*>();
}

void Bomb::display(SFMLRenderer& renderer){
    renderer.displayBomb(this);
}

void Bomb::update(std::vector<sf::Keyboard::Key>& userInputs){
    // check countdown
    // has the bomb exploded ?
    if (this->exploding_){
        // check if the explosion is ongoing
        if (this->timer_.getElapsedTime() <= Bomb::EXPLOSION_DURATION){
            // apply the explosion to the affected cases
            for (int i = 0; i < this->affectedCases_.size(); i++){
                Case* currentCase = this->affectedCases_[i];
                currentCase->applyExplosion();
            }
        } else {
            // the explosion is over
            // remove the bomb from the terrain
            Terrain* terrain = Terrain::GetInstance();
            Case* bombCase = terrain->getCase(this->x(), this->y());
            bombCase->suppElem(this);
            // delete the bomb
            delete this;
        }

    } else {
        // check if the bomb should explode
        if (this->timer_.getElapsedTime() >= Bomb::EXPLOSION_TRIGGER_TIME){
            this->explode();
            // reset the timer
            this->timer_.restart();
        }
    }
}

void Bomb::explode() {
    
    this->exploding_ = true;
    this->computeAffectedCases();

    // give the bomb back to the owner
    this->owner_->bombCount()--;
}

void Bomb::computeAffectedCases() {
    Terrain* terrain = Terrain::GetInstance();
    // retrieve bomb range
    int bombRange = this->owner_->bombRange();

    // add the bomb case to the affected cases
    this->affectedCases_.push_back(terrain->getCase(this->x(), this->y()));

    // lambda function to check and add a case to the affected cases
    // return true if the case if the crawler should continue
    auto checkAndAddCase = [this, terrain](int x, int y){
        Case* currentCase = terrain->getCase(x, y);
        // check if the case is out of the terrain
        if (currentCase == nullptr){
            return false;
        }

        // check if the case contains an indestructible block
        if (currentCase->containsIndestructibleBlock()){
            return false;
        }

        // check if the case contains a destructible block
        if (currentCase->containsDestructibleBlock()){
            // add the case to the affected cases
            this->affectedCases_.push_back(currentCase);
            return false;
        }
        // add the case to the affected cases
        this->affectedCases_.push_back(currentCase);
        return true;
    };

    // go left
    for (int i = 1; i <= bombRange; i++){
        if (!checkAndAddCase(this->x() - i, this->y())){
            break;
        }
    }
    // go right
    for (int i = 1; i <= bombRange; i++){
        if (!checkAndAddCase(this->x() + i, this->y())){
            break;
        }
    }
    // go up
    for (int i = 1; i <= bombRange; i++){
        if (!checkAndAddCase(this->x(), this->y() - i)){
            break;
        }
    }
    // go down
    for (int i = 1; i <= bombRange; i++){
        if (!checkAndAddCase(this->x(), this->y() + i)){
            break;
        }
    }
}