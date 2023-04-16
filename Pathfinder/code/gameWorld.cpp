#include "gameWorld.h"

GameWorld::GameWorld(int _gridLength){
    gridLength=_gridLength;
    setUpWorld();
}

void GameWorld::setUpWorld()
{
    float x=0,y=0;
    for(int i=1;i<gridLength;i++)
    {
        std::vector<GameTile *>rows;
        for(int j=1;j<gridLength;j++)
        {
            rows.emplace_back(new GameTile(x,y,sf::Vector2f(15.f,15.f)));
            x+=15.f;
        }
        tiles.emplace_back(rows);
        y=15.f;
    }
}