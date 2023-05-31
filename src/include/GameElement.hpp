#ifndef GAMEELEMENT_HPP
#define GAMEELEMENT_HPP
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <ctime>
#include "Displayable.hpp"


using namespace sf;

class Terrain;


class GameElement : public Displayable {         //Classe abstraite representant un element de jeu    
    public :
        
        

        GameElement(int x, int y, Terrain& t); //construit objet
        GameElement(Terrain& t);//pour construire un joueur

        //~GameElement();

        int getX(){
            return this->_x;
        }

        int getY(){
            return this->_y;
        }

        void moveTo(int x, int y);      //deplace un element


        const int& getSerial();



    protected :
        int _x;
        int _y;
        static int numberOfObjects;
        int serial;
        bool isABlock;
        


};

#endif
