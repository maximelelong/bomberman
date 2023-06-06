#ifndef CASE_HPP
#define CASE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "SFMLRenderer.hpp"
#include "AbstractGameElement.hpp"
#include "Displayable.hpp"
#include "AbstractPowerUp.hpp"
#include <typeinfo>
class Case : public Displayable
{

public:
    // constructeur
    Case(const uint x, const uint y);
    // destructeur
    ~Case(); 

    // affiche le contenu de la case
    void display(SFMLRenderer& renderer) override;

    //ajoute un element à la liste de la case
    void addElem(AbstractGameElement* elem);
    // remove an element from the list with the matching serial
    void suppElem(AbstractGameElement* elem);

    void update(std::vector<sf::Keyboard::Key>& userInputs);

    // accessors
    const uint& x() const   { return this->x_;}
    const uint& y() const   { return this->y_;}
    // return reference to the list of game elements
    std::vector<AbstractGameElement*>& gameElements() { return this->gameElements_;}

    // 'contains' functions
    bool containsBomb();
    bool containsPlayer();
    bool containsIndestructibleBlock();
    bool containsDestructibleBlock();

    bool applyExplosion();
    
    // get all elements of a certain type (or subtype) in the case by using dynamic_cast
    template <typename T>
    std::vector<T*> getAllOfType(){
        std::vector<T*> result;
        for (int i = 0; i < this->gameElements_.size(); i++){
            T* elem = dynamic_cast<T*>(gameElements_[i]);
            if (elem != nullptr){
                result.push_back(elem);
            }
        }
        return result;
    }

protected:

    std::vector<AbstractGameElement*> gameElements_;
    uint x_;
    uint y_;

private:

};

#endif