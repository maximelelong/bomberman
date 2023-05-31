#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>


#include "include/Displayable.hpp"
#include "include/Visiteur.hpp"
#include "include/Game.hpp"
#include "include/GameElement.hpp"
#include "include/Player.hpp"
#include "include/Case.hpp"
#include "include/Terrain.hpp"


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
    Visitor* V1;
    //game.setBackGround();
    // game loop
    while(game.running()){
        //update
        game.update(T);
        //render
        game.render(V1, T);
        // draw your game
        
        
    };
    // end of application
    return 0;
}