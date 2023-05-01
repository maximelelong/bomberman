#ifndef CASE_HPP
#define CASE_HPP
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

using namespace std;

class Case : public Displayable
{

public:
    Case()  //constructeur
    {  // on met des pointeurs pour permettre le polymorphisme
        vector<GameElement*> liste;
    };
    //~Case(){};  //Destructeur TODO
    void display(sf::RenderWindow* Window);   // affiche le contenu de la case

    void addElem(GameElement* elem)  //ajoute un element à la liste de la case
    {
        liste.push_back(elem);
    }


    void suppElem(GameElement* elem);

protected:

    vector<GameElement*> liste;

};

#endif