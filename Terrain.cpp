#include "Terrain.hpp"
#include "Player.hpp"

void Terrain::updateTerrain(int a)
{
    for(int i =0; i<this->listePlayers.size(); i++)
    {   
        this->listePlayers[i]->updatePlayer(a);
    }
}

Terrain::Terrain()
{
    for(int i = 0; i<100; i++)
    {   
        Case* C = new Case();
        this->listeCases.push_back(C);
    }
}

void Terrain::display(RenderWindow* Window)
{  //Display toutes les objets sur les cases
    for (size_t i = 0; i < this->listePlayers.size(); i++){   //A CHANGER CA N'AFFICHE QUE LES JOUEURSS
        this->listePlayers[i]->display(Window);
    }
}
