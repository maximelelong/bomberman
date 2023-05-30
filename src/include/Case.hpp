#ifndef CASE_HPP
#define CASE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "SFMLRenderer.hpp"
#include "AbstractGameElement.hpp"
#include "Displayable.hpp"

class Case : public Displayable
{

public:
    // constructeur
    Case(const uint x, const uint y);
    // destructeur
    //~Case(){}; 

    // affiche le contenu de la case
    void display(SFMLRenderer& renderer) override;

    //ajoute un element à la liste de la case
    void addElem(AbstractGameElement* elem);
    // remove an element from the list with the matching serial
    void suppElem(AbstractGameElement* elem);
    void update(std::vector<sf::Event>& userInputs);

    // accessors
    const uint& x() const   { return this->x_;}
    const uint& y() const   { return this->y_;}
    // return reference to the list of game elements
    std::vector<AbstractGameElement*>& gameElements() { return this->gameElements_;}


protected:

    std::vector<AbstractGameElement*> gameElements_;
    uint x_;
    uint y_;

private:

};

#endif