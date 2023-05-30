#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

#include "Game.hpp"
#include "Player.hpp"
#include "Case.hpp"
#include "Terrain.hpp"
#include "AbstractGameElement.hpp"
using namespace sf;

int main(){
    //init srand
    
    // game loop

    Game game;
    game.run();
    
    return 0;
}