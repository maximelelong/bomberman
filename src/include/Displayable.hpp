#ifndef DISPLAYABLE_HPP
#define DISPLAYABLE_HPP
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <ctime>

class Visitor;

class Displayable
{   
    public:

    virtual void display(Visitor* V1, sf::RenderWindow* Window) = 0;  //affiche l'element
};

#endif