#ifndef GAMEELEMENT_HPP
#define GAMEELEMENT_HPP

#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Displayable.hpp"

class AbstractGameElement : public Displayable{         // Abstract class to represent a game element

public :

    AbstractGameElement(const int& x, const int& y);
    //~AbstractGameElement();

    // accessors
    const int& x() const   { return this->x_;}
    const int& y() const   { return this->y_;}
    const int& serial() const   { return this->serial_;}
    
    bool moveTo(const int& x, const int& y);      //deplace un element

    virtual void update(std::vector<sf::Event>& userInputs) = 0; // update game element based on user inputs

protected :
    int x_;
    int y_;
    int serial_;
    static int s_nbOfInstances;
};

#endif
