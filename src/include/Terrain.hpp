#include "Case.hpp"
#include <vector>
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
using namespace sf;
class Player;

class Terrain : public Displayable{

    public:
        
        void display(Visitor* V1, RenderWindow* Window);
        
        Case* getCase(int x, int y)
        {
            cout<< "dans getcase "<< x*10 + y<< endl;
            return listeCases[x*10 + y];
        }

        const int getTaille()
        {
            return this->taille;
        }

        void updateTerrain();

        vector<Case*> listeCases;
        vector<Player*> listePlayers;

        Terrain();


    protected:

    
    const int taille = 11;
    
 };