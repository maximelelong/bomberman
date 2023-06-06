#include "PowerUpBomb.hpp"
#include "Case.hpp"
#include "Terrain.hpp"

void PowerUpBomb::apply(Player* owner)
{   
    owner->bombCapacity()++;
}