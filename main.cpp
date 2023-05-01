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
#include "GameElement.hpp"
using namespace sf;

int main(){
    //init srand
    
    std::srand(static_cast<unsigned>(time(NULL)));
    
    //init game engine
    Game game;
    game.setBackGround();
    Terrain T;
    
    Player P1(T);
    Player P2(T);
    Player P3(T);
    Player P4(T);
    //game.setBackGround();
    // game loop
    while(game.running()){
        //update
        game.update(T);

        //render
        game.render(T);
        
        // draw your game
        
        
    };
    // end of application
    return 0;
}