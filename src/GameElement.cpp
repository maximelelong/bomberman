#include "include/GameElement.hpp"
#include "include/Terrain.hpp"
#include "include/Case.hpp"


int GameElement::numberOfObjects = 0;

GameElement::GameElement(int x, int y, Terrain& t){

    _x = x;
    _y = y;
    serial = numberOfObjects++;

    t.getCase(x,y)->addElem(this);    //demande à la case [x,y] d'ajouter l'objet à sa liste d'objet
}

GameElement::GameElement(Terrain& t)
    {
        serial = numberOfObjects++;
    }

void GameElement::moveTo(int x, int y){       //deplace un element
    this->_x = x;
    this->_y = y;
};

const int& GameElement::getSerial()
{
    return this->serial;
};