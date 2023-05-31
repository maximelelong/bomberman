#ifndef VISITEUR_HPP
#define VISITEUR_HPP
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <ctime>
#include "Player.hpp"
#include "Block.hpp"

using namespace sf;
using namespace std;

class  Visitor{
    public:
    void DisplayJoueur(Player* J1, RenderWindow* window)
    {
        window->draw(J1->Joueur);
    }
    void DisplayBlock(Block* B1, RenderWindow* window)
    {   

        window->draw(B1->Blocks);
    }    
};


#endif