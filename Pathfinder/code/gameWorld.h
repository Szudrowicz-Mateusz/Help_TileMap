#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "gameTile.h"
#include <vector>

class GameWorld{
public:

    // Variable
    std::vector< std::vector<GameTile *>> tiles;
    int gridLength;

    // Constructor & Destructors
    GameWorld(int _gridLength);
    GameWorld()=delete;
    ~GameWorld()=default;

    // Functions
    void setUpWorld();
};