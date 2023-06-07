#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <ctime>
#include "Terrain.hpp"
#include "SFMLRenderer.hpp"

/*
Class that act as the game engine
*/

class Game
{
private:
    bool running; /**< True tant que le jeu tourne*/
    Terrain* terrain; /**< Terrain sur lequel on joue, contenant toutes les cases */
    SFMLRenderer* renderer; /**< visiteur permettant l'affichage*/
    
    // private functions
    std::vector<sf::Event> gatherInputs();
    /** @brief update toutes les classes à chaque tour
     * @param inputs commande données par les joueurs
    */
    void update(std::vector<sf::Keyboard::Key>& inputs); 
    /**
     * @brief Lance le visiteur
    */
    void render();

public:
    // constructors and destructors
    Game();
    ~Game();
    /** @brief boucle du jeu*/
    void run();
    static const int GAME_LOOP_TIME_MS;

};

#endif
