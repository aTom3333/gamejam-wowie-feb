#ifndef PLATFORMER_HPP
#define PLATFORMER_HPP

#include "ScopeGuard.hpp"
#include "Screen.hpp"
#include "constantes.hpp"

class Platformer : public Screen
{
    public:
        Platformer(sf::RenderWindow& window) : Screen{window} {}
        std::unique_ptr<Screen> execute() override;

    private:
        sf::View camera_ = sf::View(sf::FloatRect(0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y));
        float cameraSpeed_ = 1000;
};


#endif // PLATFORMER_HPP