#include "KeyEventHandler.hpp"

KeyEventHandler::KeyEventHandler() {
    // initialize the map with all the keys
    // and set their status to false
    for (int i = 0; i < sf::Keyboard::KeyCount; ++i) {
        keyStatus_[static_cast<sf::Keyboard::Key>(i)] = false;
    }
}

void KeyEventHandler::updateMap(const std::vector<sf::Event> events) {
    // iterate through the events
    for (uint i = 0; i < events.size(); ++i) {
        sf::Event event = events[i];
        // if the event is a key pressed event
        if (event.type == sf::Event::KeyPressed) {
            // update the status of the key
            keyStatus_[event.key.code] = true;
        }
        // if the event is a key released event
        else if (event.type == sf::Event::KeyReleased) {
            // update the status of the key
            keyStatus_[event.key.code] = false;
        }
    }
}

std::vector<sf::Keyboard::Key> KeyEventHandler::getPressedKeys() const {
    // create a vector to store the pressed keys
    std::vector<sf::Keyboard::Key> pressedKeys;

    // iterate through the map
    for (auto it = keyStatus_.begin(); it != keyStatus_.end(); ++it) {
        // if the key is pressed
        if (it->second) {
            // add it to the vector
            pressedKeys.push_back(it->first);
        }
    }

    // return the vector
    return pressedKeys;
}