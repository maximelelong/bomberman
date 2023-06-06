#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <vector>
#include <mutex>
#include "Case.hpp"
#include "Player.hpp"
#include "AbstractGameElement.hpp"
#include "Displayable.hpp"

// forward declaration
class AbstractGameElement;
class Case;

class Terrain : public Displayable {     // classe qui contient les cases, Singleton

    public:

        // singleton should not be cloneable or assignable
        Terrain(Terrain &other) = delete;
        void operator=(const Terrain &) = delete;

        // Get the instance of the singleton
        static Terrain *GetInstance();
                
        // Getters
        Case* getCase(const uint& x, const uint& y) const;
        const uint& sizeX() const { return this->sizeX_;}
        const uint& sizeY() const{ return this->sizeY_;}
        const std::vector<Player*>& listePlayers() const { return this->listePlayers_;}

        // remove a player from the list
        void removePlayer(Player* player);

        // overriden display from Displayable
        void display(SFMLRenderer& renderer) override;

    protected:
        // Constructor
        Terrain();
        // Destructor
        //~Terrain();
        uint sizeX_;
        uint sizeY_;
        std::vector<Case*> listeCases_;
        std::vector<Player*> listePlayers_;

    private:
        // generate N unique random numbers between min and max (inclusive)
        std::vector<int> generateUniqueIntVector(const int& min, const int& max, const int& N);

        
        // singleton instance and safeguard mutex
        static Terrain* s_instance;
        static std::mutex s_mutex;    
 };

 #endif