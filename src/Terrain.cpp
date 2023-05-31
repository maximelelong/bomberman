#include "include/Terrain.hpp"
#include "include/Player.hpp"
#include "include/Block.hpp"

void Terrain::updateTerrain()
{
    for(int i =0; i<this->listePlayers.size(); i++)
    {   

        this->listePlayers[i]->updatePlayer();
    }
}

Terrain::Terrain()
{ //le terrain fait 11 cases par 11 cases (il faut un nombre impaire), il est possible de changer mais il faut changer tt les dimensions (améliorable avec des variables globales)
    for(int i = 0; i<11; i++)
    {   
        for(int j = 0; j<11; j++)
        {
            Case* C = new Case();
            this->listeCases.push_back(C);
            //on crée un bloc si on est ni au coin sup gauche ni coin inf droit
            if (((i!=0)||(j!=0))&&((i!=10)||(j!=10))){Block* B = new Block(*this, i, j);}
            
        }
        
    }
}

void Terrain::display(Visitor* V1, RenderWindow* Window)
{  //Display toutes les objets sur les cases
    for (size_t i = 0; i < this->listeCases.size(); i++){   
        this->listeCases[i]->display(V1, Window);
    }
}
