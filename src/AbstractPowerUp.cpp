#include "AbstractPowerUp.hpp"

AbstractPowerUp::AbstractPowerUp(const int& x, const int& y) : AbstractGameElement(x,y)
{}

void AbstractPowerUp::display(SFMLRenderer& renderer)
{
    renderer.displayPowerUp(this);
}
