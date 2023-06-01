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
    bool running;
    Terrain* terrain;
    SFMLRenderer* renderer; 
    
    // private functions
    std::vector<sf::Event> gatherInputs();
    void update(std::vector<sf::Keyboard::Key>& inputs);
    void render();

public:
    // constructors and destructors
    Game();
    ~Game();

    void run();
    static const int GAME_LOOP_TIME_MS;

};

#endif
