// define guards
#ifndef USER_INPUT_OBSERVER_HPP
#define USER_INPUT_OBSERVER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class UserInputObserver
{
public:
    // UserInputObserver();
    // ~UserInputObserver();
    virtual void handleUserInput(sf::Event event) = 0;
};



#endif

