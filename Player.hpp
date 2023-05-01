#ifndef PLAYER_HPP
#define PLAYER_HPP
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

class Terrain;

class Player : public GameElement
{
private:
    // position
    int _x;
    int _y;
    // serial number
    static int nb_serial_Player;
    int serial_Player;
    // caractéristiques
    int speed;
    int range;
    // shape
    CircleShape Joueur;
    //event
    Event ev;

public:
    // constructor
    Player(Terrain& t);
    // destructor
    //~Player();
    // update
    void updatePlayer(int a);
    // render
    void display(RenderWindow* Window);
};

#endif