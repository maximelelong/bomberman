#ifndef GAME_HPP
#define GAME_HPP
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <ctime>
#include "Displayable.hpp"
//#include "Terrain.hpp"

/*
Class that act as the game engine
*/
using namespace sf;
using namespace std;

class Terrain;

class Game

{
private:
    // variables
    // window
    RenderWindow *window;
    Event ev;
    vector<RectangleShape> backGround;
    RectangleShape Case;

    // Mouse position
    Vector2i mousePosewindow;
    Vector2f mousePosView;

    // // game logic
    // int points;
    // float enemySpawnTimer;
    // float enemySpawntimerMax;
    // int maxEnnemies;

    // // Game objects
    // std::vector<RectangleShape> enemies;
    // RectangleShape enemy;

    // private function
    void initVariables();
    void initWindow();
    void initCase();
    

public:
    // constructors and destructors
    Game();
    virtual ~Game();

    // accessors
    const bool running() const;

    // functions
    void pollEvents();
    void updateMousePosition();
    // void updateEnemies();
    // void spawnEnemy();
    void setBackGround();
    void update(Terrain& T);
    // void renderEnemies();
    void renderBackGround();
    void render(Visitor* V1, Terrain& T);
};

#endif
