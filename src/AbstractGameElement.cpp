#include "AbstractGameElement.hpp"
#include "Terrain.hpp"

// static variables
int AbstractGameElement::s_nbOfInstances = 0;

AbstractGameElement::AbstractGameElement(const float& x, const float& y)
{
    x_ = x;
    y_ = y;
    AbstractGameElement::s_nbOfInstances++;
    serial_ = AbstractGameElement::s_nbOfInstances;
}

bool AbstractGameElement::moveTo(const float& x, const float& y){       //deplace un element
    
    Terrain* terrain = Terrain::GetInstance();
    Case* currCase = terrain->getCase(this->x(), this->y()); // implicit conversion from float to int (truncation)
    Case* nextCase = terrain->getCase(x, y); // idem
    
    if (currCase == nullptr || nextCase == nullptr){
        return false;
    }
    currCase->suppElem(this);
    nextCase->addElem(this);    

    this->x_ = x;
    this->y_ = y;
    return true;
};
