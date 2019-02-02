#include "AnimatedEntity.hpp"
#include "GlobalClock.hpp"
#include "RessourceLoader.hpp"

#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    
    enum state {
        Cool, Nul
    };
    
    GlobalClock::start();
    
    AnimatedEntity<state> entity(Cool, AnimatedSprite(1, sf::milliseconds(250), RessourceLoader::getTexture("sprites/walking_down.png"), sf::IntRect{340, 0, 340, 600}));
    entity.setup(Nul, AnimatedSprite(2, sf::milliseconds(250), RessourceLoader::getTexture("sprites/ringing_down.png"), sf::IntRect{0, 0, 340, 600}));
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
                entity.setState(static_cast<state>(1 - entity.getState()));
        }

        GlobalClock::lap();

        window.clear();
        entity.draw(window);
        window.display();
    }

    return 0;
}