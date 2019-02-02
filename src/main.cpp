#include "AnimatedEntity.hpp"
#include "GlobalClock.hpp"
#include "RessourceLoader.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Platformer.hpp"
#include "PlateformerPaint.h"
#include "UI.h"


void platformMain()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "SFML works!");
    GlobalClock::start();

    Platformer platformer(window, "maps/map1.txt");
    platformer.execute();
}


void testPaint()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "SFML works!");
	GlobalClock::start();

	PlateformerPaint platformer(window);
	platformer.execute();
}

void spaghet()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "SFML works!");

    GlobalClock::start();

    sf::Sprite spaghet;
    spaghet.setTexture(RessourceLoader::getTexture("sprites/spaghet.jpg"));
    sf::Sprite somebody;
    somebody.setTexture(RessourceLoader::getTexture("sprites/somebody.jpg"));
    sf::Sound sound;
    sound.setBuffer(RessourceLoader::getSoundBuffer("audio/spaghet.wav"));

    window.draw(spaghet);
    window.display();

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
			{
				goto nul;                
			}
        }
        sf::sleep(sf::milliseconds(10));
    }

    nul:

    window.clear();
    window.draw(somebody);
    window.display();

    sound.play();

    


    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                goto nul2;
        }
        sf::sleep(sf::milliseconds(10));
    }
    nul2:
    return;
}


int main()
{
	UI::loadSprites();
    //platformMain();
    //spaghet();
	testPaint();
	return 0;
}