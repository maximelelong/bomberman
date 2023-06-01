#ifndef BOMB_HPP
#define BOMB_HPP
#include <vector>
#include "AbstractGameElement.hpp"
#include "Case.hpp"

class Bomb: public AbstractGameElement
{

public:
    static const sf::Time EXPLOSION_TRIGGER_TIME;
    static const sf::Time EXPLOSION_DURATION;

    // constructor
    Bomb(const int& x, const int& y, Player* owner);
    // destructor
    //~Bomb();

    // overriden display from Displayable
    void display(SFMLRenderer& renderer) override;
    // overriden update from AbstractGameElement
    void update(std::vector<sf::Keyboard::Key>& userInputs) override;

    // accessors
    const Player* owner() const   { return this->owner_;}
    const bool& exploding() const   { return this->exploding_;}
    const std::vector<Case*>& affectedCases() const   { return this->affectedCases_;}

private:
    
    Player* owner_;
    std::vector<Case*> affectedCases_;
    sf::Clock timer_;
    bool exploding_;


    void explode();
    void computeAffectedCases();
    void applyExplosionToCase(Case* currentCase);

};
#endif