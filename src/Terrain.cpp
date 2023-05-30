#include "Terrain.hpp"
#include "Block.hpp"
#include "Bomb.hpp"

// static variables
Terrain* Terrain::s_instance{nullptr};
std::mutex Terrain::s_mutex;


/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value
 */
Terrain *Terrain::GetInstance()
{
    std::lock_guard<std::mutex> lock(s_mutex);
    if (s_instance == nullptr)
    {
        s_instance = new Terrain();
    }
    return s_instance;
}

Terrain::Terrain()
{
    sizeX_ = 11;
    sizeY_ = 11;

    for (uint i = 0; i < sizeX_; i++)
    {
        for (uint j = 0; j < sizeY_; j++)
        {
            listeCases_.push_back(new Case(i, j));
            
            // if the case is on the border, we add an indestructible block
            if (i == 0 || j == 0 || i == sizeX_ - 1 || j == sizeY_ - 1)
            {
                getCase(i, j)->addElem(new Block(i, j, true));
            }
        }
    }
    // add some blocks
    getCase(2, 2)->addElem(new Block(2, 2, false));
    getCase(2, 3)->addElem(new Block(2, 3, false));
    getCase(2, 4)->addElem(new Block(2, 4, false));


    // add a player
    Player *player1 = new Player(1, 1);
    getCase(1, 1)->addElem(player1);
    // add another player
    Player *player2 = new Player(9, 9);
    getCase(9, 9)->addElem(player2);

    // add a bomb
    getCase(3, 3)->addElem(new Bomb(3, 3, player1));
}

Case* Terrain::getCase(const uint& x, const uint& y) const{
    if (x < 0 || x >= sizeX_ || y < 0 || y >= sizeY_)
    {
        return nullptr;
    }
    return listeCases_[x*sizeX_ + y];
}

void Terrain::display(SFMLRenderer& renderer){

    renderer.displayTerrain(this);

    for (uint i = 0; i < sizeX_; i++)
    {
        for (uint j = 0; j < sizeY_; j++)
        {
            // get the case and update its content
            Case* currentCase = getCase(i, j);
            currentCase->display(renderer);
        }
    }
}