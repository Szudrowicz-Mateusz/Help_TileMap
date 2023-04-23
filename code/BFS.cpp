#include "BFS.h"

// Function that adding every posilbe path for BFS 
void posiblePaths(std::queue<sf::Vector2<char>>& path_queue,sf::Vector2<char>& actual_queue,GameWorld &gameWorld,const int map_x,const int map_y)
{
    // Right
    if(actual_queue.x-1>=0 && gameWorld.tiles[actual_queue.x-1][actual_queue.y]->isFree){
        path_queue.push(sf::Vector2<char>(actual_queue.x-1,actual_queue.y));
        // Parent postion sing in tile
        gameWorld.tiles[actual_queue.x-1][actual_queue.y]->parent_pos.x=actual_queue.x;
        gameWorld.tiles[actual_queue.x-1][actual_queue.y]->parent_pos.y=actual_queue.y;
    }

    // Left
    if(actual_queue.x+1<=map_x && gameWorld.tiles[actual_queue.x+1][actual_queue.y]->isFree){
        path_queue.push(sf::Vector2<char>(actual_queue.x+1,actual_queue.y));
        // Parent position sign in tile
        gameWorld.tiles[actual_queue.x+1][actual_queue.y]->parent_pos.x=actual_queue.x;
        gameWorld.tiles[actual_queue.x+1][actual_queue.y]->parent_pos.y=actual_queue.y;
    }
        
    // Top
    if(actual_queue.y+1<=map_y && gameWorld.tiles[actual_queue.x][actual_queue.y+1]->isFree){
        path_queue.push(sf::Vector2<char>(actual_queue.x,actual_queue.y+1));
        gameWorld.tiles[actual_queue.x][actual_queue.y+1]->parent_pos.x=actual_queue.x;
        gameWorld.tiles[actual_queue.x][actual_queue.y+1]->parent_pos.y=actual_queue.y;
    }
    
    // Bottom
    if(actual_queue.y-1>=0 && gameWorld.tiles[actual_queue.x][actual_queue.y-1]->isFree){
        path_queue.push(sf::Vector2<char>(actual_queue.x,actual_queue.y-1));
        gameWorld.tiles[actual_queue.x][actual_queue.y-1]->parent_pos.x=actual_queue.x;
        gameWorld.tiles[actual_queue.x][actual_queue.y-1]->parent_pos.y=actual_queue.y;
    }
        
}


void BFS(GameWorld &gameWorld,const int &map_x,const int &map_y,sf::RenderWindow &window)
{

sf::Vector2<char> start_position;

    for(int i=0;i<gameWorld.width;i++)
    {
        for(int j=0;j<gameWorld.length;j++)
        {
                if(gameWorld.tiles[i][j]->isStart)
                    {
                        start_position.x=i;
                        start_position.y=j;
                    }
        }
    }

    std::queue<sf::Vector2<char>> path_queue;
    path_queue.push(start_position);


    while(!path_queue.empty())
    {
        posiblePaths(path_queue,path_queue.front(),gameWorld,map_x,map_y);

        start_position.x=path_queue.front().x;
        start_position.y=path_queue.front().y;

        // Changing tiles into Visited by algorithm
        gameWorld.tiles[start_position.x][start_position.y]->isFree=false;
        gameWorld.tiles[start_position.x][start_position.y]->changeColor();

        path_queue.pop();

        // Draw
        window.clear();
        gameWorld.draw(window);
        window.display();

        // Sleep
        //std::this_thread::sleep_for(std::chrono::milliseconds(5));

        if(gameWorld.tiles[path_queue.front().x][path_queue.front().y]->isExit)
        {
            winner(path_queue.front(),gameWorld);
            break;
        }
    }


}

void winner(sf::Vector2<char> s,GameWorld &gameWorld)
{   
    // h1 stands for holder varriables
    sf::Vector2<char> h1=s;
    h1 = gameWorld.tiles[h1.x][h1.y]->parent_pos;

    while(!gameWorld.tiles[h1.x][h1.y]->isStart)
    {
        gameWorld.tiles[h1.x][h1.y]->winner();
        h1 = gameWorld.tiles[h1.x][h1.y]->parent_pos;
    }
}