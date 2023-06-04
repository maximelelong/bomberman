#include "KeyEventHandler.hpp"
#include <iostream>

int main(int argc, char **argv)
{

    KeyEventHandler handler;

    std::vector<sf::Event> events;
    
    sf::Event event;
    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::Left;
    events.push_back(event);
    sf::Event event2;
    event2.type = sf::Event::KeyPressed;
    event2.key.code = sf::Keyboard::Right;
    events.push_back(event2);

    handler.updateMap(events);

    std::vector<sf::Keyboard::Key> keys = handler.getPressedKeys();
    std::vector<sf::Keyboard::Key> expectedKeys = {sf::Keyboard::Left, sf::Keyboard::Right};
    
    // check if the vectors contains the same elements
    if(keys != expectedKeys){
        std::cout << "Test KO" << std::endl;
        return 1;
    }
    // release left key
    std::vector<sf::Event> events2;
    sf::Event event3;
    event3.type = sf::Event::KeyReleased;
    event3.key.code = sf::Keyboard::Left;
    events2.push_back(event3);

    handler.updateMap(events2);
    keys = handler.getPressedKeys();
    expectedKeys = {sf::Keyboard::Right};
    
    // check if the vectors are the same
    if(keys != expectedKeys){
        std::cout << "Test KO" << std::endl;
        return 1;
    }
  

    return 0;
}