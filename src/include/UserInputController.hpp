// define guards
#ifndef USERINPUTCONTROLLER_HPP
#define USERINPUTCONTROLLER_HPP

// include statements
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "UserInputObserver.hpp"

class UserInputController
{
public:

    UserInputController(/* args */);
    // ~UserInputController();

    void addObserver(UserInputObserver* observer);
    void removeObserver(UserInputObserver* observer);
    void notifyObservers(sf::Event event);

    
private:
    sf::Window* window;
    std::vector<UserInputObserver*> observers;
};



#endif