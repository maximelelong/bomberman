#include "include/Terrain.hpp"
#include "include/Visiteur.hpp"
#include "include/Block.hpp"

Block::Block(Terrain &t, int x, int y, bool Destructable): GameElement(t)
{   
    t.getCase(x,y)->addElem(this);
    IsDestructable = Destructable;
    if (Destructable)
    {
        //Blocks.setFillColor();
    }
}
void Block::display(Visitor *V1, RenderWindow *Window)
{   
    //Window->draw(this->Joueur);
    V1->DisplayBlock(this, Window);
}

