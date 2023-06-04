#include "PowerUpRange.hpp"
#include "Case.hpp"
#include "Terrain.hpp"

void PowerUpRange::display(SFMLRenderer& renderer)
{
    renderer.displayPowerUpRange(this);
}


void PowerUpRange::Apply(Player* owner)
{   
    owner->bombRange()++;
}