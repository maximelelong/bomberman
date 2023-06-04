#include "PowerUpBomb.hpp"
#include "Case.hpp"
#include "Terrain.hpp"

void PowerUpBomb::display(SFMLRenderer& renderer)
{
    renderer.displayPowerUpBomb(this);
}


void PowerUpBomb::Apply(Player* owner)
{   
    owner->bombCapacity()++;
}