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

class Block : public GameElement{

    private:

        bool IsDestructable;

    public:

    Block(Terrain& t, int x, int y, bool Destructable);
    // destructor
    //~Block();
    void display(Visitor* V1, RenderWindow* Window);
    // shape
    RectangleShape Blocks;

};

#endif