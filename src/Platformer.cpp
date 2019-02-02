#include "Platformer.hpp"


std::unique_ptr<Screen> Platformer::execute()
{
    while(window_.isOpen())
    {
        sf::Event event{};
        while(window_.pollEvent(event)) {
            auto res = gestionEvent(event);
            if(res)
                return std::move(*res);
        }
    }
}
