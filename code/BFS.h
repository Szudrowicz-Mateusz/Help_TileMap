#pragma once

#include "gameTile.h"
#include "gameWorld.h"

#include <queue>
#include <chrono>
#include <thread>
#include <iostream>

void posiblePaths(std::queue<sf::Vector2<char>>& path_queue,sf::Vector2<char>& actual_queue,GameWorld &gameWorld,const int map_x,const int map_y);

void BFS(GameWorld &gameWorld,const int &map_x,const int &map_y,sf::RenderWindow &window);

void winner(sf::Vector2<char> s,GameWorld &gameWorld);