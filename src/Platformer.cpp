#include "Platformer.hpp"
#include "GlobalClock.hpp"
#include "RessourceLoader.hpp"
#include <fstream>
#include <string>
#include "Utilities.hpp"
#include "UI.h"
#include "AnimatedEntity.hpp"
#include "FallingEntity.hpp"


Platformer::Platformer(sf::RenderWindow& window, const std::filesystem::path& mapPath) : Screen{window}
{
    if(mapPath.extension() != ".txt")
        throw std::invalid_argument("Map must be a txt.");

    std::ifstream file(RessourceLoader::getPath(mapPath.u8string()), std::ios::in);
    if(!file.is_open())
        throw std::runtime_error("Can't open from :" + mapPath.u8string());

    std::string line;
    while(std::getline(file, line))
    {
        if(!line.empty() && line[0] != '#')
        {
            std::vector<std::string> coords = split(line);
            if(coords.size() == 2)
            {
                mapSize_ = sf::Vector2f(stof(coords.at(0)), stof(coords.at(1)));
            }
            else
            {
                // TODO Créer les plateformes adaptées
                //platforms_.emplace_back(sf::Vector2f(stof(coords.at(2)), stof(coords.at(3))));
                //platforms_.back().setPosition({stof(coords.at(0)), stof(coords.at(1))});
                //platforms_.back().setFillColor(sf::Color::Green);
            }
        }
    }
    
    // TODO Enlever ce truc de test
    entities_.push_back(std::make_unique<AnimatedEntity<int>>(0, AnimatedSprite(1, sf::milliseconds(250), RessourceLoader::getTexture("sprites/fixed_test_platform.png"))));
    entities_.push_back(std::make_unique<FallingEntity>(std::make_unique<AnimatedEntity<int>>(0, AnimatedSprite(1, sf::milliseconds(250), RessourceLoader::getTexture("sprites/falling_test_platform.png"))), entities_));
    
    entities_.front()->setPosition(200, 400);
    entities_.back()->setPosition(200, 0);
}

std::unique_ptr<Screen> Platformer::execute()
{
    ScopeGuard scopeGuard([this]() { window_.setView(window_.getDefaultView()); });

    GlobalClock::lap();

    while(window_.isOpen())
    {
		sf::Vector2f mousePos = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
        sf::Event event{};
        while(window_.pollEvent(event))
        {
            auto res = gestionEvent(event);
            if(res)
                return std::move(*res);

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				if (UI::actionMouseClicked(mousePos))
					return nullptr;
			}
        }

        GlobalClock::lap();
		sf::Time elapsedTime = GlobalClock::lapTime();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			camera_.move(0, -cameraSpeed_ * elapsedTime.asSeconds());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			camera_.move(0, cameraSpeed_ * elapsedTime.asSeconds());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			camera_.move(-cameraSpeed_ * elapsedTime.asSeconds(), 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			camera_.move(cameraSpeed_ * elapsedTime.asSeconds(), 0);
		}

        for(auto& entity : entities_)
            entity->update();

        window_.clear();
        window_.setView(camera_);

        for(auto& entity : entities_)
            entity->draw(window_);

		window_.setView(uiView_);
		UI::update(mousePos);
		UI::draw(window_);

        window_.display();

        sf::sleep(sf::milliseconds(10));
    }
}
