#include "AbstractGameElement.hpp"
#include "Terrain.hpp"

// static variables
int AbstractGameElement::s_nbOfInstances = 0;

AbstractGameElement::AbstractGameElement(const int& x, const int& y)
{
    x_ = x;
    y_ = y;
    AbstractGameElement::s_nbOfInstances++;
    serial_ = AbstractGameElement::s_nbOfInstances;
}

bool AbstractGameElement::moveTo(const int& x, const int& y){       //deplace un element
    
    Terrain* terrain = Terrain::GetInstance();
    Case* currCase = terrain->getCase(this->x(), this->y());
    Case* nextCase = terrain->getCase(x, y);
    if (currCase == nullptr || nextCase == nullptr){
        return false;
    }
    currCase->suppElem(this);
    nextCase->addElem(this);    

    this->x_ = x;
    this->y_ = y;
    return true;
};
