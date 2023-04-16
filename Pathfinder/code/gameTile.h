#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>



class GameTile{
public:

    // Shape off tile
    sf::RectangleShape rec;

    // Varriables
    bool isFree;
    bool isExit;
    bool isStart;
    sf::Vector2f pos;

    // Construtors & Destructors
    GameTile(float x, float y, sf::Vector2f recSize);
    GameTile()=delete;
    ~GameTile()=default;
};