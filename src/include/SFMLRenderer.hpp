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
class AbstractPowerUp;
class SFMLRenderer
{

public:
    SFMLRenderer();
    ~SFMLRenderer();

    void displayPlayer(const Player* player);
    void displayTerrain(const Terrain* terrain);
    void displayCase(const Case* case_);
    void displayBlock(const Block* block);
    void displayBomb(const Bomb* bomb);
    void displayPowerUp(const AbstractPowerUp* powerUp);

    // Getters and setters
    sf::RenderWindow& window() { return this->window_; }
    const sf::RenderWindow& window() const { return this->window_; }

    void render();

    void displayWinnerScreen(const Player* player);


private:
    sf::RenderWindow window_;
    sf::Texture texture_;
    sf::Texture texture_2;
    sf::Font font_;

    std::vector<sf::Sprite> backgroundSprites_;
    std::vector<sf::Sprite> blocksSprites_;
    std::vector<sf::Sprite> objectsSprites_;
    std::vector<sf::Sprite> playersSprites_;
};

#endif