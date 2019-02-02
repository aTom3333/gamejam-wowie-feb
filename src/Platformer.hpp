#ifndef PLATFORMER_HPP
#define PLATFORMER_HPP

#include "ScopeGuard.hpp"
#include "Screen.hpp"
#include "constantes.hpp"
#include <filesystem>

class Platformer : public Screen
{
    public:
        Platformer(sf::RenderWindow& window, const std::filesystem::path& mapPath);
        std::unique_ptr<Screen> execute() override;

    private:
        sf::View camera_ = sf::View(sf::FloatRect(0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y));
        float cameraSpeed_ = 10000;

        std::vector<sf::RectangleShape> platforms_;

        sf::Vector2f mapSize_;
};


#endif // PLATFORMER_HPP