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
        void display(SFMLRenderer& renderer) override;

    protected:
        // Constructor
        Terrain();
        // Destructor
        //~Terrain();
        uint sizeX_;
        uint sizeY_;
        std::vector<Case*> listeCases_;

    private:
        // overriden display from Displayable
        
        // singleton instance and safeguard mutex
        static Terrain* s_instance;
        static std::mutex s_mutex;    
 };

 #endif