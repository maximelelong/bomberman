#include "Game.hpp"
#include "Terrain.hpp"
#include "Case.hpp"
#include "Player.hpp"


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
    this->running = true;
    std::cout << "Game is running" << std::endl;
    while (running)
    {
        std::vector<sf::Event> inputs = this->gatherInputs();
        // handle high level inputs
        for (uint i = 0; i < inputs.size(); i++)
        {
            if (inputs[i].type == sf::Event::Closed)
            {
                this->running = false;
            }
        }

        this->update(inputs);
        this->render();
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

void Game::update(std::vector<sf::Event>& inputs){
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


