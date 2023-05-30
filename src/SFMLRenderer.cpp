#include "SFMLRenderer.hpp"
#include "Case.hpp"
#include "Terrain.hpp"
#include "Player.hpp"
#include "Block.hpp"
#include "Bomb.hpp"
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

    if(player->id() == 0) {
        sprite.setTextureRect(sf::IntRect(42, 167, 17, 20));
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
        sprite.setTextureRect(sf::IntRect(57, 205, 16, 16));
    } else {
        sprite.setTextureRect(sf::IntRect(78, 205, 16, 16));
    }

    sprite.setPosition(block->x() * 16, block->y() * 16);
    this->blocksSprites_.push_back(sprite);
}

void SFMLRenderer::displayBomb(Bomb* bomb){
    sf::Sprite sprite;
    sprite.setTexture(texture_);
    sprite.setTextureRect(sf::IntRect(188, 204, 16, 16));
    sprite.setPosition(bomb->x() * 16, bomb->y() * 16);
    this->objectsSprites_.push_back(sprite);

    
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

