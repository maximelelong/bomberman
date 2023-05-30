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
    void update(std::vector<sf::Event>& userInputs);

    // accessors
    const int& id() const   { return this->id_;}
    const int& speed() const   { return this->speed_;}
    const int& bombCapacity() const   { return this->bombCapacity_;}
    const int& bombRange() const   { return this->bombRange_;}
    // Setters
    void setSpeed(const int& speed) { this->speed_ = speed;}
    void setBombCapacity(const int& bombCapacity) { this->bombCapacity_ = bombCapacity;}
    void setBombRange(const int& bombRange) { this->bombRange_ = bombRange;}

    bool placeBomb();

private:

    // caractéristiques
    int id_;
    int speed_;
    int bombCapacity_;
    int bombRange_;
    int bombCount_;

    bool canMove(const uint& x, const uint& y);
    bool handleKeyStroke(const sf::Event& event);
    static int s_playerCount;
    
};

#endif