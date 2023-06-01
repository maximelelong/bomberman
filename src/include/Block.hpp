#ifndef BLOCK_HPP
#define BLOCK_HPP
#include <vector>
#include "AbstractGameElement.hpp"
#include "SFMLRenderer.hpp"
#include "PowerUp.hpp"

class Block : public AbstractGameElement
{
public:
    // constructor
    Block(const int& x, const int& y, const bool& isDestructible, PowerUp* powerUp = nullptr);
    // destructor
    //~Block();

    // overriden display from Displayable
    void display(SFMLRenderer& renderer) override;

    // accessors
    const bool& isDestructible() const   { return this->isDestructible_;}
    void destroy();

    // operators stream
    friend std::ostream& operator<<(std::ostream& os, const Block& block);
private:
    
    PowerUp* powerUp_;
    bool isDestructible_;

    
};

#endif