#include "include/Case.hpp"


using namespace sf;


void Case::suppElem(GameElement* elem){    //parcourt la liste, et si l'element pointé par l'iterateur a le meme serial que l'element a supprimer, le supprime
        for (int i = 0; i < this->liste.size(); i++){
            if (liste[i]->getSerial() == elem->getSerial()){
                liste.erase(liste.begin()+i);
                break;
            }
        }

        
    }

void Case::display(Visitor* V1, RenderWindow* Window){  //parcourt la liste d'element d'une case et les affiches
    for (int i = 0 ; i<liste.size(); i++)
    {
        liste[i]->display(V1, Window);
    }
}
