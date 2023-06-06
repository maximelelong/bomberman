#ifndef BLOCK_HPP
#define BLOCK_HPP
#include <vector>
#include "AbstractGameElement.hpp"
#include "SFMLRenderer.hpp"

class AbstractPowerUp;

class Block : public AbstractGameElement
{
public:
    // constructor
    Block(const int& x, const int& y, const bool& isDestructible, AbstractPowerUp* powerUp = nullptr);
    // destructor
    //~Block();

    // overriden display from Displayable
    void display(SFMLRenderer& renderer) override;

    // accessors
    const bool& isDestructible() const   { return this->isDestructible_;}
    void destroy();
    void setPower(AbstractPowerUp* PU);
    const AbstractPowerUp* powerUp() const { return this->powerUp_;}
    // operators stream
    friend std::ostream& operator<<(std::ostream& os, const Block& block);
private:
    
    AbstractPowerUp* powerUp_;
    bool isDestructible_;

    
};

#endif