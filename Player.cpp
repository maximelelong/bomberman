#include "Player.hpp"
#include "Terrain.hpp"


int Player::nb_serial_Player = 0;

Player::Player(Terrain& t) : GameElement(t)   //crée un joueur
{   
    this->speed = 2;
    this->range = 1;
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
        _x = 600;
        _y = 440;
        this->Joueur.setFillColor(Color::Red);
        this->Joueur.setPosition(_x, _y);
    }
    if (serial_Player == 2)
    {
        _x = 10;
        _y = 440;
        this->Joueur.setFillColor(Color::Green);
        this->Joueur.setPosition(_x, _y);

    }
    if (serial_Player == 3)
    {
        _x = 600;
        _y = 7;
        this->Joueur.setFillColor(Color::Yellow);
        this->Joueur.setPosition(_x, _y);
    }
    this->Joueur.setRadius(20);
    this->Joueur.setOutlineColor(Color::Black);
    int b = int(this->Joueur.getPosition().x)%64;
    int c= int(this->Joueur.getPosition().y)%48;
    t.getCase(b,c)->addElem(this); 
    t.listePlayers.push_back(this);
};

void Player::updatePlayer(int a)
{
    /**
     * update position of 1 player
     * /!\ TODO
     * upgrade capacity
    */

    if(this->serial_Player == 0)
    {
        if(a == 1)
        {   
            _y -= 5;
        }
        if(a == 2)
        {
            _y += 5;
        }
        if(a == 3)
        {
            _x += 5;
        }
        if(a == 4)
        {
            _x -= 5;
        }
    }
    if(this->serial_Player == 1)
    {
        if(a == 5)
        {   
            _y -= 5;
        }
        if(a == 6)
        {
            _y += 5;
        }
        if(a == 7)
        {
            _x += 5;
        }
        if(a == 8)
        {
            _x -= 5;
        }
    }

    this->Joueur.setPosition(_x, _y);
}

void Player::display(RenderWindow* Window)
{   
    Window->draw(this->Joueur);
}

