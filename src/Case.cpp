#include <iostream>
#include "Case.hpp"

Case::Case(const uint x, const uint y)
{
    x_ = x;
    y_ = y;
}


void Case::suppElem(AbstractGameElement* elem){    //parcourt la liste, et si l'element pointé par l'iterateur a le meme serial que l'element a supprimer, le supprime
    for (int i = 0; i < this->gameElements_.size(); i++){
        if (gameElements_[i]->serial() == elem->serial()){
            gameElements_.erase(gameElements_.begin()+i);
            // std::cout << "case (" << this->x() << "," << this->y()  << ") Element supprimé (serial : " << elem->serial() << ")"  << std::endl;
            break;
        }
    }       
}

void Case::addElem(AbstractGameElement* elem){     //ajoute un element à la liste de la case
    this->gameElements_.push_back(elem);
    // std::cout << "case (" << this->x() << "," << this->y()  << ") Element ajouté (serial : " << elem->serial() << ")"  << std::endl;
}

void Case::display(SFMLRenderer& renderer){

    for (int i = 0; i < this->gameElements_.size(); i++){
        this->gameElements_[i]->display(renderer);
    }
}

void Case::update(std::vector<sf::Event>& userInputs){
    for (int i = 0; i < this->gameElements_.size(); i++){
        this->gameElements_[i]->update(userInputs);
    }
}