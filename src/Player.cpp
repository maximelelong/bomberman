#include "Player.hpp"
#include "Terrain.hpp"
#include "Case.hpp"
#include "Block.hpp"
#include "Bomb.hpp"
#include <vector>
#include <iostream>
// for ceil
#include <cmath>

int Player::s_playerCount = 0;

Player::Player(const float& startPosX, const float& startPosY) : AbstractGameElement(startPosX, startPosY)
{
    this->id_ = Player::s_playerCount++;
    this->speed_ = 0.1;
    this->bombCapacity_ = 1;
    this->bombRange_ = 1;
}

void Player::display(SFMLRenderer& renderer){
    renderer.displayPlayer(this);
}

bool Player::handleKey(const sf::Keyboard::Key &key) {
    
    // we suppose that we handle the key pressed event
    bool handled = true;

    float nextX = this->x_;
    float nextY = this->y_;

    switch (this->id_)
    {
    case 0:         // Player 1
        switch (key)
        {
        case sf::Keyboard::Up:
            nextY = this->y_ - this->speed_;
            break;
        case sf::Keyboard::Down:
            nextY = this->y_ + this->speed_;
            break;
        case sf::Keyboard::Left:
            nextX = this->x_ - this->speed_;
            break;
        case sf::Keyboard::Right:
            nextX = this->x_ + this->speed_;
            break;
        case sf::Keyboard::C:
            this->placeBomb();
            break;
        default:
            // we don't handle this event
            handled = false;
            break;
        }
        break;

    case 1:    // Player 2

        switch (key)
        {
        case sf::Keyboard::Z:
            nextY = this->y_ - this->speed_;
            break;
        case sf::Keyboard::S:
            nextY = this->y_ + this->speed_;
            break;
        case sf::Keyboard::Q:
            nextX = this->x_ - this->speed_;
            break;
        case sf::Keyboard::D:
            nextX = this->x_ + this->speed_;
            break;
        case sf::Keyboard::Space:
            this->placeBomb();
            break;
        default:
            // we don't handle this event
            handled = false;
            break;
        }
        break;
    default:
        handled = false;
        break;
    }

    if (this->canMove(nextX, nextY)){
        this->moveTo(nextX, nextY);
    }
    return handled;
}

void Player::PowerUpOnCase()
{   
    Terrain* terrain = Terrain::GetInstance();
    Case* currentCase = terrain->getCase(x_,y_);
    for (int i=0; i<currentCase->gameElements().size(); i++)
    {
        if(currentCase->isPowerUp(i))
        {
            PowerUp* PU = currentCase->getPowerUp(i);
            PU->Apply(this);
            currentCase->suppElem(PU);
        }
    }
}

void Player::update(std::vector<sf::Keyboard::Key>& userInputs){
    
    // iterate over all user inputs
    for(auto it = userInputs.begin(); it != userInputs.end();){
        sf::Keyboard::Key key = *it;
        bool handled = this->handleKey(key);
        if (handled){
            it = userInputs.erase(it);
        } else {
            ++it;
        }
    }
    this->PowerUpOnCase();
}

bool Player::canMove(const float& nextX, const float& nextY){

    Terrain* terrain = Terrain::GetInstance();

    // if the player hitbox is currently touching a bomb (possible only if the player just placed a bomb)
    // he should be able to move (to avoid being stuck)

    // compute position of the corners of the hitbox
    float hitboxCurr_x1 = this->x_ - this->hitboxWidth_/2;
    float hitboxCurr_x2 = this->x_ + this->hitboxWidth_/2;
    float hitboxCurr_y1 = this->y_ - this->hitboxHeight_/2;
    float hitboxCurr_y2 = this->y_ + this->hitboxHeight_/2;

    // get the case in which each corner is
    Case* topLeftCase = terrain->getCase(hitboxCurr_x1, hitboxCurr_y1);
    Case* topRightCase = terrain->getCase(hitboxCurr_x2, hitboxCurr_y1);
    Case* bottomLeftCase = terrain->getCase(hitboxCurr_x1, hitboxCurr_y2);
    Case* bottomRightCase = terrain->getCase(hitboxCurr_x2, hitboxCurr_y2);

    // iterate over all cases and check if there is a bomb in it
    bool playerIsTouchingBomb = false;
    std::vector<Case*> currCorners = {topLeftCase, topRightCase, bottomLeftCase, bottomRightCase};
    for (auto it = currCorners.begin(); it != currCorners.end(); ++it){
        Case* currCase = *it;
        // check if not nullptr
        if (currCase){
            // check if the is a bomb in the case
            bool containsBomb = currCase->containsBomb();
            if (containsBomb){
                playerIsTouchingBomb = true;
                break;
            }
        }
    }
    
    // compute position of the corners of the hitbox
    float hitboxNext_x1 = nextX - this->hitboxWidth_/2;
    float hitboxNext_x2 = nextX + this->hitboxWidth_/2;
    float hitboxNext_y1 = nextY - this->hitboxHeight_/2;
    float hitboxNext_y2 = nextY + this->hitboxHeight_/2;

    // get the case in which each corner is
    Case* nextTopLeftCase = terrain->getCase(hitboxNext_x1, hitboxNext_y1);
    Case* nextTopRightCase = terrain->getCase(hitboxNext_x2, hitboxNext_y1);
    Case* nextBottomLeftCase = terrain->getCase(hitboxNext_x1, hitboxNext_y2);
    Case* nextBottomRightCase = terrain->getCase(hitboxNext_x2, hitboxNext_y2);

    // iterate over all cases and check if there is a block in it
    std::vector<Case*> corners = {nextTopLeftCase, nextTopRightCase, nextBottomLeftCase, nextBottomRightCase};
    for (auto it = corners.begin(); it != corners.end(); ++it){
        Case* currCase = *it;
        // check if not nullptr
        if (currCase){
            // check if there is a block in the case
            bool containsBlock = currCase->containsIndestructibleBlock() || currCase->containsDestructibleBlock();
            bool containsBomb = currCase->containsBomb();

            if (containsBlock){
                return false;
            }
            // the player can move on a bomb only to move out of it
            if (containsBomb && !playerIsTouchingBomb){
                return false;
            }
        }
    }

    return true;
}

bool Player::placeBomb(){
    Terrain* terrain = Terrain::GetInstance();
    
    
    if ((this->bombCount_ >= this->bombCapacity_)||(terrain->getCase(this->x_,this->y_)->containsBomb())){
        return false;
    }
    Case* currCase = terrain->getCase(this->x_, this->y_);

    Bomb* bomb = new Bomb(this->x_, this->y_, this);
    currCase->addElem(bomb);
    this->bombCount_++;
    return true;
}