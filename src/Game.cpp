#include "Game.hpp"
#include "Terrain.hpp"
#include "Case.hpp"
#include "Player.hpp"

using namespace sf;

//private functions
void Game::initVariables()
{
    this->window = nullptr;
    // this->points = 0;
    // this->enemySpawntimerMax = 20.f;
    // this->enemySpawnTimer = this->enemySpawntimerMax;
    // this->maxEnnemies = 10;
}

void Game::initWindow()
{
    this->window = new RenderWindow(VideoMode(640, 480), "game 1", Style::Titlebar | Style::Close);

    this->window->setFramerateLimit(20);
}

// void Game::initEnemies()
// {
//     this->enemy.setPosition(50, 50);
//     this->enemy.setSize(Vector2f(100, 100));
//     this->enemy.setFillColor(Color::Cyan);
//     //this->enemy.setOutlineColor(Color::Green);
//     //this->enemy.setOutlineThickness(1.f);
// }

void Game::initCase()
{
    this->Case.setPosition(50, 50);
    this->Case.setSize(Vector2f(64,48));
    this->Case.setFillColor(Color::Cyan);
    //this->enemy.setOutlineColor(Color::Green);
    //this->enemy.setOutlineThickness(1.f);
}

//constructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    // this->initEnemies();
    this->initCase();
}
//destructors
Game::~Game()
{
    delete this->window;
}

//Accessors
const bool Game::running() const
{
    return this->window->isOpen();  //retourne vrai si la fenetre est toujours ouverte 
}

//functions

void Game::updateMousePosition()
{
    /**
        @return void
        Update the mouse position
            Mouse position relative to the window (vector2i)
    */
   this->mousePosewindow = Mouse::getPosition(*this->window);
   this->mousePosView = this->window->mapPixelToCoords(this->mousePosewindow);
}

// void Game::updateEnemies()
// {   
//     //updating the timer for enemy spawning
//     if (this->enemies.size() < this->maxEnnemies)
//     {
//         /**
//          *  @return void
//          *  
//          * update the enemy spawn timer and spawns enemies when total amount of enemies is smaller than the max
//          * moves enemies downwards
//          * removes enemies at the edge of the screen 
//         */
//         if (this->enemySpawnTimer >= this->enemySpawntimerMax)
//         {   
//             //spawn an enemy and restart the timer
//             this->spawnEnemy();
//             this->enemySpawnTimer = 0.f;
//         }
//         else {
//             this->enemySpawnTimer++;
//         }
//     }

//     //Move the enemies and updating
//     //for(auto &e : this->enemies)  PRATIQUE
//     for(int i =0; i < this->enemies.size(); i++)
//     {
//         bool deleted = false;
//         this->enemies[i].move(0.f, 5.f);

//         //check if clicked upon
//         if(Mouse::isButtonPressed(Mouse::Left))
//         {
//             if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
//             {
//                 deleted = true;
//             }
//         }
//         //if enemy is at the bottom of the screen
//         if(this->enemies[i].getPosition().y + this->enemies[i].getSize().y> this->window->getSize().y)
//         {
//             deleted = true;
//         }
        
//         if(deleted)
//         {
//             this->enemies.erase(this->enemies.begin()+i);
//         }

//     }
// }

// void Game::spawnEnemy()
// {
//     /**
//      *  @return void
//      * 
//      * Spawn enemies and sets their colors and position
//      * add enemies to the vector
//     */
//    this->enemy.setPosition(
//         static_cast<float>(rand()%static_cast<int>((this->window->getSize().x - this->enemy.getSize().x))),//pos is define with the top right corner of the rectangle so we need to substract the width
//         0.f
//    );(this->enemy);

//    this->enemy.setFillColor(Color::Green);
//    this->enemies.push_back

// }

// void Game::renderEnemies()
// {   
//     //rendering all the enemies
//     for(auto &e : this->enemies)
//     {
//         this->window->draw(e);
//     }
// }

void Game::setBackGround()
{
    for (int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            this->Case.setPosition(64*i, 48*j);
            this->Case.setOutlineThickness(2);
            this->Case.setOutlineColor(Color::Red);
            this->Case.setFillColor(Color(255, 255, 255, 100));
            this->backGround.push_back(this->Case);
        }
    }
   
}

void Game::renderBackGround()
{   
    
    for(auto &e : this->backGround)
    {
        this->window->draw(e);
    }
    
}





void Game::pollEvents(int& a)
{
    //event polling
        while (this->window->pollEvent(this->ev))
        {
            switch (this->ev.type)
            {
            case Event::Closed:
                this->window->close();
                break;
            
            case Event::KeyPressed:
                if (this->ev.key.code == Keyboard::Escape)
                this->window->close();
                if (this->ev.key.code == Keyboard::Up)
                a=1;
                if (this->ev.key.code == Keyboard::Down)
                a=2;
                if (this->ev.key.code == Keyboard::Right)
                a=3; 
                if (this->ev.key.code == Keyboard::Left)
                a=4; 
                if (this->ev.key.code == Keyboard::Z)
                a=5;
                if (this->ev.key.code == Keyboard::S)
                a=6;
                if (this->ev.key.code == Keyboard::D)
                a=7; 
                if (this->ev.key.code == Keyboard::Q)
                a=8;             
                break;
            
            default:
                break;
            }
        };
}



void Game::update(Terrain& T)
{   
    int a = 0;
    this->pollEvents(a);

    this->updateMousePosition();
    
    T.updateTerrain(a);



    // this->updateEnemies();

}

void Game::render(Terrain& T)
{
    /**
        @return void
        
        -clear old frame
        -render objets
        -display frame in window
    */
    
    this->window->clear();


    //Draw game objects
    //this->window->draw(this->enemy);

    // this->renderEnemies();
    this->renderBackGround();


    
    for(int i =0; i<T.listePlayers.size(); i++)
    {   
        T.display(this->window);
    }
    //this->window->draw(this->Case);
    this->window->display();



}