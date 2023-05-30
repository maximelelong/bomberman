#ifndef SMFLRENDERER_HPP
#define SMFLRENDERER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

// forward declaration
class Player;
class Terrain;
class Case;
class Block;
class Bomb;
class SFMLRenderer
{

public:
    SFMLRenderer();
    ~SFMLRenderer();

    void displayPlayer(Player* player);
    void displayTerrain(Terrain* terrain);
    void displayCase(Case* case_);
    void displayBlock(Block* block);
    void displayBomb(Bomb* bomb);


    // Getters and setters
    sf::RenderWindow& window() { return this->window_; }
    const sf::RenderWindow& window() const { return this->window_; }

    void render();


private:
    sf::RenderWindow window_;
    sf::Texture texture_;

    std::vector<sf::Sprite> backgroundSprites_;
    std::vector<sf::Sprite> blocksSprites_;
    std::vector<sf::Sprite> objectsSprites_;
    std::vector<sf::Sprite> playersSprites_;
};

#endif