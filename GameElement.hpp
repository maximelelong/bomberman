#include "Displayable.hpp"

class GameElement : public Displayable{         //Classe abstraite representant un element de jeu    
    public :
        virtual void display() = 0;  //affiche l'element

        GameElement(int x, int y, terrain t){
            _x = x;
            _y = y;
            serial = numberOfObjects++;

            t.getCase(x,y).addGameElement(self);    //demande à la case [x,y] d'ajouter l'objet à sa liste d'objet
        }
        ~GameElement();

        int getX(){
            return self._x;
        }

        int getY(){
            return self._y;
        }

        void moveTo(int x, int y){       //deplace un element
            _x = x;
            _y = y;
        }

    protected :

        int _x;
        int _y;
        static int numberOfObjects = 0;
        const int serial;
        


}
