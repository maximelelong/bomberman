#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <vector>
#include "AbstractGameElement.hpp"
#include "UserInputObserver.hpp"
#include "SFMLRenderer.hpp"

class Player : public AbstractGameElement
{

public:
    // constructor
    Player(const uint& startPosX, const uint& startPosY);
    // destructor
    //~Player();

    // overriden display from Displayable
    void display(SFMLRenderer& renderer) override;
    void update(std::vector<sf::Keyboard::Key>& userInputs);

    // accessors
    const int& id() const   { return this->id_;}
    const int& speed() const   { return this->speed_;}
    const int& bombCapacity() const   { return this->bombCapacity_;}
    const int& bombRange() const   { return this->bombRange_;}
    const int& bombCount() const   { return this->bombCount_;}
    const bool& isDying() const   { return this->isDying_;}
    // Setters
    int& speed()   { return this->speed_;}
    int& bombCapacity()   { return this->bombCapacity_;}
    int& bombRange()   { return this->bombRange_;}
    int& bombCount()   { return this->bombCount_;}

    bool placeBomb();

private:

    // caractéristiques
    int id_;
    int speed_ = 0;
    int bombCapacity_ = 0;
    int bombRange_ = 0;
    int bombCount_ = 0;

    bool isDying_ = false;

    bool canMove(const uint& x, const uint& y);
    bool handleKey(const sf::Keyboard::Key& key);
    static int s_playerCount;
    
};

#endif