#include "AnimatedEntity.hpp"
#include "GlobalClock.hpp"
#include "RessourceLoader.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Platformer.hpp"


int maintest()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    enum state
    {
        Cool,
        Nul
    };

    GlobalClock::start();

    //AnimatedEntity<state> entity(Cool, AnimatedSprite(1, sf::milliseconds(250), RessourceLoader::getTexture("sprites/walking_down.png"), sf::IntRect{340, 0, 340, 600}));
    //entity.setup(Nul, AnimatedSprite(2, sf::milliseconds(250), RessourceLoader::getTexture("sprites/ringing_down.png"), sf::IntRect{0, 0, 340, 600}));

    std::vector<sf::RectangleShape> shapes;

    const int n = 10;

    for(size_t i = 0 ; i < n ; ++i) {
        for(size_t j = 0 ; j < n ; ++j)
        {
			shapes.emplace_back(sf::Vector2f(n/2, n/2));
            shapes.back().setFillColor(sf::Color::Green);
            shapes.back().setPosition(n*i, n*j);
        } 
    }

    sf::View mainView(sf::FloatRect(0, 0, 1200, 600));

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
            {
                sf::Time elapsedTime = GlobalClock::lapTime();
                const int speed = 500;

                switch(event.key.code)
                {
                    case sf::Keyboard::Up :
                        mainView.move(0, speed * elapsedTime.asSeconds());
                        break;
                    case sf::Keyboard::Right :
                        mainView.move(speed * elapsedTime.asSeconds(), 0);
                        break;
                    case sf::Keyboard::Down :
                        mainView.move(0, - speed * elapsedTime.asSeconds());
                        break;
                    case sf::Keyboard::Left :
                        mainView.move(- speed * elapsedTime.asSeconds(), 0);
                        break;
                    default :
                        break;
                }
            }
        }

        GlobalClock::lap();

        window.clear();

        window.setView(mainView);

        for(auto& shape : shapes)
            window.draw(shape);

        window.display();
    }

    return 0;
}

int main()
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
    }
    nul2:

    Platformer platformer(window);
    platformer.execute();
    return 0;
}
