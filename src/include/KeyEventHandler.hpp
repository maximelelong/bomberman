#ifndef KEY_EVENT_HANDLER_HPP
#define KEY_EVENT_HANDLER_HPP

#include <SFML/Window.hpp>
#include <map>
#include <vector>

/**this class is used to handle key events
 * it will store the key status (pressed or not)
 * when receiving a key event, it will update the status
 */
class KeyEventHandler {
    public:
        KeyEventHandler();
        // ~KeyEventHandler();

        void updateMap(const std::vector<sf::Event> events);
        std::vector<sf::Keyboard::Key> getPressedKeys() const;

    private:
        std::map<sf::Keyboard::Key, bool> keyStatus_;
};

#endif // KEY_EVENT_HANDLER_HPP