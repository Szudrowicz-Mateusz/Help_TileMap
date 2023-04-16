#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "gameTile.h"
#include "gameWorld.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(512,512),"SFML Tiles", sf::Style::Close | sf::Style::Resize);
    
    GameWorld gameWorld(16);

    while(window.isOpen()){

        // Events
        sf::Event event;
        while(window.pollEvent(event)){
            switch ((event.type)){

                case sf::Event::Closed:
                window.close();
                break;
            }
        }

        

        window.clear();
        

        // Drawing map
        for(int i=0;i<gameWorld.gridLength;i++)
        {
            for(int j=0;j<gameWorld.gridLength;j++)
            {
                window.draw(gameWorld.tiles[i][j]->rec);
            }
        }

        window.display();

    }
}