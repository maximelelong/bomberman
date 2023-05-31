#ifndef BLOC_HPP
#define BLOC_HPP
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <ctime>
#include "GameElement.hpp"

using namespace sf;
class Block : public GameElement{

    private:


    public:

        bool IsDestructable;
        Block(Terrain& t, int x, int y);
        // destructor
        //~Block();
        void display(Visitor* V1, RenderWindow* Window);
        // shape
        Sprite  Blocks;
        Texture texture;


};

#endif