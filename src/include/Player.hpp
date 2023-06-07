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
    Player(const float& startPosX, const float& startPosY);
    // destructor
    //~Player();

    /** overriden display from Displayable*/
    void display(SFMLRenderer& renderer) override;
    /** @brief à jour le joueur*/
    void update(std::vector<sf::Keyboard::Key>& userInputs);

    // accessors
    const int& id() const   { return this->id_;}
    const float& speed() const   { return this->speed_;}
    const int& bombCapacity() const   { return this->bombCapacity_;}
    const int& bombRange() const   { return this->bombRange_;}
    const int& bombCount() const   { return this->bombCount_;}
    const bool& isDying() const   { return this->isDying_;}
    // Setters
    float& speed()   { return this->speed_;}
    int& bombCapacity()   { return this->bombCapacity_;}
    int& bombRange()   { return this->bombRange_;}
    int& bombCount()   { return this->bombCount_;}

    /** @brief Permet de déposer une bombe*/
    bool placeBomb();
    /** @brief Mort du Joueur*/
    void die();

    // default values
    static const float DEFAULT_SPEED;
    static const float MAX_SPEED;
    static const int DEFAULT_BOMB_CAPACITY;
    static const int DEFAULT_BOMB_RANGE;

private:

    // caractéristiques
    int id_;
    float speed_ = 0; 
    int bombCapacity_ = 0;
    int bombRange_ = 0;
    int bombCount_ = 0;

    // hitbox
    float hitboxWidth_ = 0.55;
    float hitboxHeight_ = 0.55;

    bool isDying_ = false;
    /** @brief determine si le joueur peut se deplacer*/
    bool canMove(const float& x, const float& y);
    bool handleKey(const sf::Keyboard::Key& key);
    static int s_playerCount;
    void PowerUpOnCase();
    
};

#endif