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

    /**
     * @brief affiche le Joueur
     * @param player Joueur à afficher
    */
    void displayPlayer(const Player* player);
    /**
     * @brief affiche le Terrain
     * @param terrain Terrain à afficher
    */
    void displayTerrain(const Terrain* terrain);
    /**
     * @brief affiche une case
     * @param case_ case à afficher
    */
    void displayCase(const Case* case_);
    /**
     * @brief affiche le Block
     * @param block Block à afficher
    */
    void displayBlock(const Block* block);
    /**
     * @brief affiche la bombe
     * @param bomb bombe à afficher
    */
    void displayBomb(const Bomb* bomb);
    /**
     * @brief affiche le Power up
     * @param powerUp Power up à afficher
    */
    void displayPowerUp(const AbstractPowerUp* powerUp);

    // Getters and setters
    sf::RenderWindow& window() { return this->window_; }
    const sf::RenderWindow& window() const { return this->window_; }
    /**
     * @brief affiche tout le jeu
     * 
    */
    void render();
/**
 * @brief affiche l'ecran de victoire
 * @param player Joueur gagnant
*/
    void displayWinnerScreen(const Player* player);


private:
    sf::RenderWindow window_; /**< fenetre ou tout est affiché*/
    sf::Texture texture_; /**< premiere feuille de texture ou on prend nos sprites*/
    sf::Texture texture_2; /**< deuxieme feuille de texture ou on prend nos sprites*/
    sf::Font font_;

    std::vector<sf::Sprite> backgroundSprites_;
    std::vector<sf::Sprite> blocksSprites_;
    std::vector<sf::Sprite> objectsSprites_;
    std::vector<sf::Sprite> playersSprites_;
};

#endif