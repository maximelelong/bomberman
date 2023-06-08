#include "Terrain.hpp"
#include "Block.hpp"
#include "Bomb.hpp"
#include "PowerUpSkate.hpp"
#include "PowerUpDeath.hpp"
#include "PowerUpBomb.hpp"
#include "PowerUpRange.hpp"
#include <iostream>
#include <random>
#include <set>
#include <typeindex>
#include <map>

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
    sizeX_ = 15;
    sizeY_ = 15;

    // fill the map with empty cases
    // also add indestructible blocks on the borders
    for (uint i = 0; i < sizeX_; i++)
    {
        for (uint j = 0; j < sizeY_; j++)
        {
            listeCases_.push_back(new Case(i, j));
            
            // if the case is on the border, we add an indestructible block
            if (i == 0 || j == 0 || i == sizeX_ - 1 || j == sizeY_ - 1)
            {
                getCase(i, j)->addElem(new Block(i, j, false));
            }
        }
    }

    // add indestructible blocks
    for (uint i = 2; i < sizeX_ - 2; i++)
    {
        for (uint j = 2; j < sizeY_ - 2; j++)
        {
            if (i % 2 == 0 && j % 2 == 0)
            {
                getCase(i, j)->addElem(new Block(i, j, false));
            }
        }
    }

    // fill the rest of the map with destructible blocks
    // this means filling a row each 2 rows and a column each 2 columns
    for (uint i = 1; i < sizeX_ - 1; i++)
    {
        for (uint j = 1; j < sizeY_ - 1; j++)
        {
            if (i % 2 == 1 || j % 2 == 1)
            {
                getCase(i, j)->addElem(new Block(i, j, true));
            }
        }
    }

    // remove the blocks at the top left and bottom right corners (for the players)
    getCase(1, 1)->gameElements().clear();
    getCase(1, 2)->gameElements().clear();
    getCase(2, 1)->gameElements().clear();
    getCase(sizeX_ - 2, sizeY_ - 2)->gameElements().clear();
    getCase(sizeX_ - 2, sizeY_ - 3)->gameElements().clear();
    getCase(sizeX_ - 3, sizeY_ - 2)->gameElements().clear();

    // get all the cases with a destructible block
    std::vector<Block*> destructibleBlocks;
    for(Case* currentCase : listeCases_){
        for(AbstractGameElement* currentElem : currentCase->gameElements()){
            if(typeid(*currentElem) == typeid(Block)){
                Block* currentBlock = dynamic_cast<Block*>(currentElem);
                if(currentBlock->isDestructible()){
                    destructibleBlocks.push_back(currentBlock);
                }
            }
        }
    }
    
    // Number of powerups to place in a map
    std::map<std::type_index, int> nbPowerups;
    nbPowerups[typeid(PowerUpSkate)] = 5;
    nbPowerups[typeid(PowerUpDeath)] = 5;
    nbPowerups[typeid(PowerUpBomb)] = 5;
    nbPowerups[typeid(PowerUpRange)] = 5;

    // calculate the total number of powerups
    int nb_powerups = 0;
    for (auto it = nbPowerups.begin(); it != nbPowerups.end(); it++)
    {
        nb_powerups += it->second;
    }

    // generate random indexes to place the powerups
    std::vector<int> randomIndexes = generateUniqueIntVector(0, destructibleBlocks.size()-1, nb_powerups);

    // iterate over map keys
    for (auto it = nbPowerups.begin(); it != nbPowerups.end(); it++)
    {
        // iterate over the number of powerups to place
        for (int i = 0; i < it->second; i++)
        {
            // get a random index
            int randomIndex = randomIndexes.back();
            randomIndexes.pop_back();

            // get the corresponding block
            Block* currentBlock = destructibleBlocks[randomIndex];



            // add the powerup
            if (it->first == typeid(PowerUpSkate))
            {
                currentBlock->setPower(new PowerUpSkate(currentBlock->x(), currentBlock->y()));
            }
            else if (it->first == typeid(PowerUpDeath))
            {
                currentBlock->setPower(new PowerUpDeath(currentBlock->x(), currentBlock->y()));
            }
            else if (it->first == typeid(PowerUpBomb))
            {
                currentBlock->setPower(new PowerUpBomb(currentBlock->x(), currentBlock->y()));
            }
            else if (it->first == typeid(PowerUpRange))
            {
                currentBlock->setPower(new PowerUpRange(currentBlock->x(), currentBlock->y()));
            }
        }
    }
    
    
    // add players
    Player* player1 = new Player(1.5, 1.5);
    getCase(1, 1)->addElem(player1);
    Player* player2 = new Player(sizeX_ - 1.5, sizeY_ - 1.5);
    getCase(sizeX_ - 2, sizeY_ - 2)->addElem(player2);
    listePlayers_.push_back(player1);
    listePlayers_.push_back(player2);
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

void Terrain::removePlayer(Player* player){
    listePlayers_.erase(std::remove(listePlayers_.begin(), listePlayers_.end(), player), listePlayers_.end());
}

std::vector<int> Terrain::generateUniqueIntVector(const int& min, const int& max, const int& N) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    std::set<int> unique_numbers;
    while (unique_numbers.size() < N) {
        int size_before = unique_numbers.size();
        unique_numbers.insert(dis(gen));
        int size_after = unique_numbers.size();
        if (size_after > size_before) {
        }
    }
    std::vector<int> numbers(unique_numbers.begin(), unique_numbers.end());
    return numbers;
}
