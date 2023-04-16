#include "gameTile.h"

GameTile::GameTile(float x, float y,sf::Vector2f recSize)
{
    // Tunning variables
    pos = sf::Vector2f(x,y);

    // Setting up rectangles
    rec.setPosition(pos);
    rec.setSize(recSize);
    rec.setFillColor(sf::Color::Blue);

    // Setting up booleans
    isFree=true;
    isStart=false;
    isExit=false;
}
