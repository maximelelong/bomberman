#include "include/Terrain.hpp"
#include "include/Visiteur.hpp"
#include "include/Block.hpp"


Block::Block(Terrain &t, int x, int y): GameElement(x, y, t)
{   
    isABlock = true;
    //obtention de la texture pour les cases
    if ( !texture.loadFromFile("/home/leonard/Documents/Info/Jeu_C++/Brique.jpg"))
    {
        cout << "Load failed" << endl;
        system("pause");
    }
    texture.setRepeated(true);
    this->Blocks.setTexture(texture);
    this->Blocks.setTextureRect(IntRect(100, 100, 50, 34));
    this->Blocks.setPosition(this->getX()*64+7, this->getY()*48+6);

    //test pour savoir si le bloc est destructible
    if((x==0)||(y==0)||((y%2==0)||(x%2==0)))
    {
        IsDestructable = 1;
    }

    else
    {
        IsDestructable = 0;
    }

    if (this->IsDestructable)
    {
        this->Blocks.setColor(Color(255, 255, 255, 50));
    }
    else
    {
        this->Blocks.setColor(Color::Blue);
    }

    
}
void Block::display(Visitor *V1, RenderWindow *Window)
{   
    //Window->draw(this->Joueur);
    V1->DisplayBlock(this, Window);
}

