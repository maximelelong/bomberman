#include "PowerUpSkate.hpp"
#include "PowerUpDeath.hpp"
#include "Case.hpp"
#include "Terrain.hpp"

void PowerUpSkate::display(SFMLRenderer& renderer)
{
    renderer.displayPowerUpSkate(this);
}


void PowerUpSkate::Apply(Player* owner)
{
    if(owner->speed()<0.2)
    {
        owner->speed()+=0.1;
    }
}