#include "Platformer.hpp"
#include "GlobalClock.hpp"


std::unique_ptr<Screen> Platformer::execute()
{
    ScopeGuard scopeGuard([this]() { window_.setView(window_.getDefaultView());});

    GlobalClock::lap();

    while(window_.isOpen())
    {
        sf::Event event{};
        while(window_.pollEvent(event))
        {
            auto res = gestionEvent(event);
            if(res)
                return std::move(*res);

            sf::Time elapsedTime = GlobalClock::lapTime();


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                camera_.move(0, cameraSpeed_ * elapsedTime.asSeconds());
            }
            else if(sf::Keyboard::isKeyPressed((sf::Keyboard::Down)))
            {
                 camera_.move(0, - cameraSpeed_ * elapsedTime.asSeconds());
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                camera_.move(- cameraSpeed_ * elapsedTime.asSeconds(), 0);
            }
            else if(sf::Keyboard::isKeyPressed((sf::Keyboard::Right)))
            {
                camera_.move(cameraSpeed_ * elapsedTime.asSeconds(), 0);
            }
        }

        window_.clear();
        window_.setView(camera_);

        window_.display();
    }
}
