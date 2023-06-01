#include "Game.hpp"
#include "Terrain.hpp"
#include "Case.hpp"
#include "Player.hpp"
#include "KeyEventHandler.hpp"

const int Game::GAME_LOOP_TIME_MS = 1000/100;

// constructors and destructors
Game::Game(){
    this->terrain = Terrain::GetInstance();
    this->running = false;
    this->renderer = new SFMLRenderer();
}

Game::~Game(){
    delete this->terrain;
    delete this->renderer;
}

void Game::run(){
    std::cout << "Game is running" << std::endl;
    this->running = true;
    KeyEventHandler keyEventHandler;

    // Game loop clock
    
    sf::Clock gameLoopClock;
    while (running)
    {
        std::vector<sf::Event> rawInputs = this->gatherInputs();
        // if the rawInputs contains a quit event, stop the game
        
        for (uint i = 0; i < rawInputs.size(); i++)
        {   sf::Event currentEvent = rawInputs[i];
            if (currentEvent.type == sf::Event::Closed || (currentEvent.type == sf::Event::KeyPressed && currentEvent.key.code == sf::Keyboard::Escape)){
                this->running = false;
            }
        }

        keyEventHandler.updateMap(rawInputs);
        std::vector<sf::Keyboard::Key> pressedKeys = keyEventHandler.getPressedKeys();

        
        this->update(pressedKeys);
        this->render();

        sf::Time timeToSleep = sf::milliseconds(Game::GAME_LOOP_TIME_MS) - gameLoopClock.restart();
        if (timeToSleep.asMicroseconds() > 0)
            sf::sleep(timeToSleep);
    }

}

std::vector<sf::Event> Game::gatherInputs(){
    std::vector<sf::Event> inputs;
    sf::Event event;
    while (this->renderer->window().pollEvent(event))
    {
        inputs.push_back(event);
    }
    return inputs;
}

void Game::update(std::vector<sf::Keyboard::Key>& inputs){
    // iterate over case in terrain
    for (uint i = 0; i < this->terrain->sizeX(); i++)
    {
        for (uint j = 0; j < this->terrain->sizeY(); j++)
        {
            // get the case and update its content
            Case* currentCase = this->terrain->getCase(i, j);
            currentCase->update(inputs);
        }
    }
}

void Game::render(){
    this->renderer->render();
}


