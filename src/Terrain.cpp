#include "include/Terrain.hpp"
#include "include/Player.hpp"

void Terrain::updateTerrain()
{
    for(int i =0; i<this->listePlayers.size(); i++)
    {   

        this->listePlayers[i]->updatePlayer();
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

void Terrain::display(Visitor* V1, RenderWindow* Window)
{  //Display toutes les objets sur les cases
    for (size_t i = 0; i < this->listeCases.size(); i++){   //A CHANGER CA N'AFFICHE QUE LES JOUEURSS
        this->listeCases[i]->display(V1, Window);
    }
}
