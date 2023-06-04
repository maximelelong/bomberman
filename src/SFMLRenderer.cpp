#include "SFMLRenderer.hpp"
#include "Case.hpp"
#include "Terrain.hpp"
#include "Player.hpp"
#include "Block.hpp"
#include "Bomb.hpp"
#include "PowerUpSkate.hpp"
#include "PowerUpDeath.hpp"
#include "PowerUpBomb.hpp"
#include "PowerUpRange.hpp"
#include <iostream>

SFMLRenderer::SFMLRenderer(){
    
    // member variables init
    this->blocksSprites_ = std::vector<sf::Sprite>();
    this->objectsSprites_ = std::vector<sf::Sprite>();
    this->playersSprites_ = std::vector<sf::Sprite>();
    
    int blockWidth = 16;

    this->window_.create(sf::VideoMode(blockWidth*11, blockWidth*11), "SFML window");
    this->window_.setFramerateLimit(60);

    // resize the window to be 3times bigger
    this->window_.setSize(sf::Vector2u(blockWidth*11*3, blockWidth*11*3));
    
    // load the texture
    if (!texture_.loadFromFile("../assets/bomberman_texture.gif"))
    {
        std::cout << "Error while loading texture" << std::endl;
    }

    if (!texture_2.loadFromFile("../assets/bomberman_texture.png"))
    {
        std::cout << "Error while loading texture" << std::endl;
    }
}

SFMLRenderer::~SFMLRenderer(){
    this->window_.close();
}


void SFMLRenderer::displayCase(Case* case_){
    // draw a gray square with a dark gray border based on the case's position
    sf::Color caseColor(128, 128, 128);
    sf::Color borderColor(64, 64, 64);
    sf::RectangleShape rectangle(sf::Vector2f(16, 16));
    rectangle.setFillColor(caseColor);
    rectangle.setOutlineThickness(1);
    rectangle.setOutlineColor(borderColor);
    rectangle.setPosition(case_->x() * 16, case_->y() * 16);
    window_.draw(rectangle);
}


void SFMLRenderer::displayTerrain(Terrain* terrain){
    // window dimensions
    uint windowWidth = this->window_.getSize().x;
    uint windowHeight = this->window_.getSize().y;

    // draw the terrain background
    sf::RectangleShape background(sf::Vector2f(windowHeight, windowWidth));
    sf::Color backgroundColor(19, 173, 45);
    background.setFillColor(backgroundColor);
    window_.draw(background);
}

void SFMLRenderer::displayPlayer(Player* player){
    sf::Sprite sprite;
    sprite.setTexture(texture_);
    sprite.setOrigin(7.5, 10);
    
    if(player->id() == 0) {
        sprite.setTextureRect(sf::IntRect(42, 167, 17, 20));
        // set origin to the center of the sprite
    } else if (player->id() == 1) {
        sprite.setTextureRect(sf::IntRect(120, 167, 17, 20));
    } else if (player->id() == 2) {
        sprite.setTextureRect(sf::IntRect(195, 168, 17, 20));   
    }

    sprite.setPosition(player->x() * 16, player->y() * 16);
    this->playersSprites_.push_back(sprite);
}

void SFMLRenderer::displayBlock(Block* block){
    sf::Sprite sprite;
    sprite.setTexture(texture_);

    if (block->isDestructible()){
        sprite.setTextureRect(sf::IntRect(78, 205, 16, 16));
    } else {
        sprite.setTextureRect(sf::IntRect(57, 205, 16, 16));
    }

    sprite.setPosition(block->x() * 16, block->y() * 16);
    this->blocksSprites_.push_back(sprite);
}

void SFMLRenderer::displayBomb(Bomb* bomb){
    
    if (bomb->exploding())
    {
        sf::Sprite sprite_explosion_center;
        sprite_explosion_center.setTexture(texture_);
        sprite_explosion_center.setTextureRect(sf::IntRect(69, 477, 16, 16));
        sprite_explosion_center.setPosition(bomb->x() * 16, bomb->y() * 16);

        sf::Sprite sprite_explosion_up;
        sprite_explosion_up.setTexture(texture_);
        sprite_explosion_up.setTextureRect(sf::IntRect(69, 461, 16, 16));
        sf::Sprite sprite_explosion_down;
        sprite_explosion_down.setTexture(texture_);
        sprite_explosion_down.setTextureRect(sf::IntRect(69, 491, 16, 16));
        sf::Sprite sprite_explosion_left;
        sprite_explosion_left.setTexture(texture_);
        sprite_explosion_left.setTextureRect(sf::IntRect(54, 476, 16, 16));
        sf::Sprite sprite_explosion_right;
        sprite_explosion_right.setTexture(texture_);
        sprite_explosion_right.setTextureRect(sf::IntRect(84, 476, 16, 16));

        //iterate over the bomb affected cases
        for (Case* case_ : bomb->affectedCases())
        {
            // if the case is the bomb's position, draw the center sprite
            if (case_->x() == bomb->x() && case_->y() == bomb->y())
            {
                sprite_explosion_center.setPosition(case_->x() * 16, case_->y() * 16);
                this->objectsSprites_.push_back(sprite_explosion_center);

            }
            // if the case is on the same line as the bomb, draw the horizontal sprite
            else if (case_->y() == bomb->y())
            {
                // if the case is on the left of the bomb, draw the left sprite
                if (case_->x() < bomb->x())
                {
                    sprite_explosion_left.setPosition(case_->x() * 16, case_->y() * 16);
                    this->objectsSprites_.push_back(sprite_explosion_left);
                }
                else
                {
                    sprite_explosion_right.setPosition(case_->x() * 16, case_->y() * 16);
                    this->objectsSprites_.push_back(sprite_explosion_right);
                }
            }
            // if the case is on the same column as the bomb, draw the vertical sprite
            else if (case_->x() == bomb->x())
            {
                // if the case is above the bomb, draw the up sprite
                if (case_->y() < bomb->y())
                {
                    sprite_explosion_up.setPosition(case_->x() * 16, case_->y() * 16);
                    this->objectsSprites_.push_back(sprite_explosion_up);
                }
                else
                {
                    sprite_explosion_down.setPosition(case_->x() * 16, case_->y() * 16);
                    this->objectsSprites_.push_back(sprite_explosion_down);
                }
            }
        }


    } else {    // not exploding
        
        sf::Sprite sprite_not_exploded;
        sprite_not_exploded.setTexture(texture_);
        sprite_not_exploded.setTextureRect(sf::IntRect(188, 204, 16, 16));
        sprite_not_exploded.setPosition(bomb->x() * 16, bomb->y() * 16);
        this->objectsSprites_.push_back(sprite_not_exploded);
    }

    
}

void SFMLRenderer::displayPowerUpSkate(PowerUpSkate* skate)
{
    sf::Sprite sprite_power_up;
    sprite_power_up.setTexture(texture_2);
    sprite_power_up.setTextureRect(sf::IntRect(6, 55, 16, 16));
    sprite_power_up.setPosition(skate->x() * 16, skate->y() * 16);
    this->objectsSprites_.push_back(sprite_power_up);
}

void SFMLRenderer::displayPowerUpDeath(PowerUpDeath* death)
{
    sf::Sprite sprite_power_up;
    sprite_power_up.setTexture(texture_2);
    sprite_power_up.setTextureRect(sf::IntRect(66, 55, 16, 16));
    sprite_power_up.setPosition(death->x() * 16, death->y() * 16);
    this->objectsSprites_.push_back(sprite_power_up);
}

void SFMLRenderer::displayPowerUpBomb(PowerUpBomb* bomb)
{
    sf::Sprite sprite_power_up;
    sprite_power_up.setTexture(texture_2);
    sprite_power_up.setTextureRect(sf::IntRect(46, 55, 16, 16));
    sprite_power_up.setPosition(bomb->x() * 16, bomb->y() * 16);
    this->objectsSprites_.push_back(sprite_power_up);
}

void SFMLRenderer::displayPowerUpRange(PowerUpRange *Range)
{
    sf::Sprite sprite_power_up;
    sprite_power_up.setTexture(texture_2);
    sprite_power_up.setTextureRect(sf::IntRect(46, 75, 16, 16));
    sprite_power_up.setPosition(Range->x() * 16, Range->y() * 16);
    this->objectsSprites_.push_back(sprite_power_up);
}

void SFMLRenderer::render(){
    
    // clear the window
    this->window_.clear();
    
    // clear all the sprites
    this->blocksSprites_.clear();
    this->objectsSprites_.clear();
    this->playersSprites_.clear();

    // draw the terrain
    Terrain* terrain = Terrain::GetInstance();
    terrain->display(*this);

    // The sprites are now filled with the objects to display
    // We can now draw them
    for (sf::Sprite sprite : this->blocksSprites_){
        this->window_.draw(sprite);
    }
    for (sf::Sprite sprite : this->objectsSprites_){
        this->window_.draw(sprite);
    }
    for (sf::Sprite sprite : this->playersSprites_){
        this->window_.draw(sprite);
    }

    // display the window
    this->window_.display();
    
}

