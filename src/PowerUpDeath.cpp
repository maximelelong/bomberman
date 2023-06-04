#include "PowerUpDeath.hpp"
#include "Case.hpp"
#include "Terrain.hpp"

void PowerUpDeath::display(SFMLRenderer& renderer)
{
    renderer.displayPowerUpDeath(this);
}


void PowerUpDeath::Apply(Player* owner)
{   
    if(owner->speed()>= 0.2)
    {
        owner->speed()-=0.1;
    }
}