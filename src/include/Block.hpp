#ifndef BLOCK_HPP
#define BLOCK_HPP
#include <vector>
#include "AbstractGameElement.hpp"
#include "SFMLRenderer.hpp"

class AbstractPowerUp;

/**
 * @brief Classe représentant les blocs du jeu, destructibles ou non
 * 
*/

class Block : public AbstractGameElement
{
public:
    // constructor
    /** 
     * @brief Constructeur
     * @param x position en x
     * @param y position en y
     * @param isDestructible bool indiquant si le bloc est destructible ou non
    */
    Block(const int& x, const int& y, const bool& isDestructible, AbstractPowerUp* powerUp = nullptr);
    // destructor
    //~Block();

    // overriden display from Displayable
    /**
     * @brief fonction d'affichage du bloc
     * @param renderer Permet d'appeller le visiteur
     * 
    */
    void display(SFMLRenderer& renderer) override;

    // accessors
    /**
     * Retourne si le bloc est destructible ou non
    */
    const bool& isDestructible() const   { return this->isDestructible_;}
    void destroy();
    void setPower(AbstractPowerUp* PU);
    const AbstractPowerUp* powerUp() const { return this->powerUp_;}
    // operators stream
    friend std::ostream& operator<<(std::ostream& os, const Block& block);
private:
    
    AbstractPowerUp* powerUp_; /**< Contient le power placé dans le bloc*/
    bool isDestructible_;   /**< Deterpmine si un bloc est destructible ou non*/

    
};

#endif