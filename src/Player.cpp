#include "Player.hpp"
#include "Terrain.hpp"
#include "Case.hpp"
#include "Block.hpp"
#include "Bomb.hpp"
#include <vector>

int Player::s_playerCount = 0;

Player::Player(const uint& startPosX, const uint& startPosY) : AbstractGameElement(startPosX, startPosY)
{
    this->id_ = Player::s_playerCount++;
    this->speed_ = 1;
}

void Player::display(SFMLRenderer& renderer){
    renderer.displayPlayer(this);
}

bool Player::handleKeyStroke(const sf::Event &event) {
    
    // we suppose that we handle the key pressed event
    bool handled = true;

    if(event.type == sf::Event::KeyPressed){

        int nextX = this->x_;
        int nextY = this->y_;

        switch (this->id_)
        {
        case 0:         // Player 1
            switch (event.key.code)
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
            default:
                // we don't handle this event
                handled = false;
                break;
            }
            break;

        case 1:    // Player 2

            switch (event.key.code)
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
    }
    return handled;
}

void Player::update(std::vector<sf::Event>& userInputs){
    
    // iterate over all user inputs
    for(auto it = userInputs.begin(); it != userInputs.end();){
        sf::Event event = *it;
        bool handled = this->handleKeyStroke(event);
        if (handled){
            it = userInputs.erase(it);
        } else {
            ++it;
        }
    }
}

bool Player::canMove(const uint& nextX, const uint& nextY){

    Terrain* terrain = Terrain::GetInstance();
    Case* caseNext = terrain->getCase(nextX, nextY);

    if (caseNext == nullptr){
        return false;
    }

    // check if there is a block or a bomb on the next case
    std::vector<AbstractGameElement*> elements = caseNext->gameElements();
    for (size_t i = 0; i < elements.size(); i++)
    {
        // check type of element
        if (typeid(*elements[i]) == typeid(Block) || typeid(*elements[i]) == typeid(Bomb)){
            return false;
        }
    }

    return true;
}

bool Player::placeBomb(){
    Terrain* terrain = Terrain::GetInstance();
    Case* currCase = terrain->getCase(this->x_, this->y_);

    Bomb* bomb = new Bomb(this->x_, this->y_, this);
    currCase->addElem(bomb);
}