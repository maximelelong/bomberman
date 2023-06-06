#include "PowerUpRange.hpp"
#include "Terrain.hpp"

void PowerUpRange::apply(Player* owner)
{   
    owner->bombRange()++;
}