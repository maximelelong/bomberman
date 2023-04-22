#include "Case.hpp"


void Case::suppElem(GameElement* elem){    //parcourt la liste, et si l'element pointé par l'iterateur a le meme serial que l'element a supprimer, le supprime
        for (list<GameElement*>::iterator it = liste.begin(); it!=list.end(); it ++){
            if (**it.serial == *elem.serial){
                liste.erase(it);
                break;
            }
        }

        
    }

void Case::displayCase(){  //parcourt la liste d'element d'une case et les affiches
    for (list<GameElement*>::iterator it = liste.begin(); it!=list.end(); it ++){
            **it.GameElement::display();
        }
}
