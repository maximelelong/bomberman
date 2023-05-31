#include "include/Player.hpp"
#include "include/Terrain.hpp"
#include "include/Visiteur.hpp"

class Visitor;


int Player::nb_serial_Player = 0;

Player::Player(Terrain& t) : GameElement(t)   //crée un joueur
{   
    isABlock = false;
    this->speed = 1;
    this->range = 2;
    this->serial_Player = nb_serial_Player++;
    if (serial_Player == 0)
    {
        this->Joueur.setFillColor(Color::Blue);
        _x = 10;
        _y = 7;
        this->Joueur.setPosition(_x, _y);
    }
    if (serial_Player == 1)
    {
        _x = 664;
        _y = 488;
        this->Joueur.setFillColor(Color::Red);
        this->Joueur.setPosition(_x, _y);
    }
    if (serial_Player == 2)
    {
        _x = 10;
        _y = 488;
        this->Joueur.setFillColor(Color::Green);
        this->Joueur.setPosition(_x, _y);

    }
    if (serial_Player == 3)
    {
        _x = 664;
        _y = 7;
        this->Joueur.setFillColor(Color::Yellow);
        this->Joueur.setPosition(_x, _y);
    }
    this->Joueur.setRadius(10);
    this->Joueur.setOutlineColor(Color::Black);
    int b = int(this->Joueur.getPosition().x)/64;
    int c= int(this->Joueur.getPosition().y)/48;
    t.getCase(b,c)->addElem(this); 
    t.listePlayers.push_back(this);
};

void Player::updatePlayer()
{
    /**
     * update position of 1 player
     * /!\ TODO
     * upgrade capacity
    */

    if(this->serial_Player == 0)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {   
            _y -= this->speed*5;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            _y += this->speed*5;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            _x += this->speed*5;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            _x -= this->speed*5;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        { 
            Bomb* B = new Bomb("mettre le terrain ici", int(this->_y/48), int(this->_x/64)); //il faut trouver un moyen de récupérer les terrain
        }
    }
    if(this->serial_Player == 1)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {   
            _y -= this->speed*5;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            _y += this->speed*5;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            _x += this->speed*5;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            _x -= this->speed*5;
        }
    }

    this->Joueur.setPosition(_x, _y);

}

void Player::display(Visitor* V1, RenderWindow* Window)
{   
    //Window->draw(this->Joueur);
    V1->DisplayJoueur(this, Window);
}

char* canImove()
{
   //retourne une chaine de caracteres ex: 'oono' permettant de savoir si on peut ou pas se deplacer dans une direction 
   //dans cet exemple on peut se déplacer a gauche, a droite, pas en haut, et en bas
   //il suffit de regarder dans la case correspondant a la position du joueur si il se deplace (deplacement = _x+speed*5 pour un deplacement vers la droite)
   //dans cette case on regarde si les GameElements on true ou false a leur attribut "isABlock" ainsi on sait si, en ce déplacant on va dans une case contenant un bloc
   //probleme: il faut récuperer le terrain or on ne l'a pas. Il faut trouver un solution afin de pouvoir faire un terrain.getCase(_x, _y).liste, parcourir cette liste et tester si il y a un bloc dans la case
   // cela fait 4 test pour chaque deplacemet
   //on pourra ensuite utiliser cette fonction dans uptade_player
   return "ooo";
}

