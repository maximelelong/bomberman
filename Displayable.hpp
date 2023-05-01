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
#include "GameElement.hpp"



class Displayable
{   
    public:

    virtual void display(sf::RenderWindow* Window) = 0;  //affiche l'element
};

#endif