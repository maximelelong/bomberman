#ifndef GAMEELEMENT_HPP
#define GAMEELEMENT_HPP

#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Displayable.hpp"

class AbstractGameElement : public Displayable{         // Abstract class to represent a game element

public :

    AbstractGameElement(const float& x, const float& y);
    //~AbstractGameElement();

    // accessors
    const float& x() const   { return this->x_;}
    const float& y() const   { return this->y_;}
    const int& serial() const   { return this->serial_;}

    // mutators
    float& x(const float& x)   { return this->x_ = x;}
    float& y(const float& y)   { return this->y_ = y;} 
    
    bool moveTo(const float& x, const float& y);      //deplace un element

    // To be overriden by subclasses (not mandatory)
    virtual void update(std::vector<sf::Keyboard::Key>& userInputs) {}; // update game element based on user inputs

protected :
    float x_;
    float y_;
    int serial_;
    static int s_nbOfInstances;
};

#endif
