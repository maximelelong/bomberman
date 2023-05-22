#include "include/Player.hpp"
#include "include/Terrain.hpp"
#include "include/Visiteur.hpp"

class Visitor;


int Player::nb_serial_Player = 0;

Player::Player(Terrain& t) : GameElement(t)   //crée un joueur
{   
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

