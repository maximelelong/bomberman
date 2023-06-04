#include "Terrain.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    Terrain* terrain = Terrain::GetInstance();

    // check if the returned pointer is not null
    if(terrain == nullptr){
        std::cout << "Test KO: the returned pointer is null" << std::endl;
        return 1;
    }

    // check the singleton pattern
    Terrain* terrain2 = Terrain::GetInstance();
    if(terrain != terrain2){
        std::cout << "Test KO: the singleton pattern is not respected" << std::endl;
        return 1;
    }

    // check getCase
    Case* currCase = terrain->getCase(3, 1);
    if(currCase == nullptr){
        std::cout << "Test KO: the returned case is null" << std::endl;
        return 1;
    }
    if(currCase->x() != 3 || currCase->y() != 1){
        std::cout << "Test KO: the returned case has wrong coordinates" << std::endl;
        return 1;
    }

    
    return 0;
}