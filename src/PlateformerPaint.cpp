#include "PlateformerPaint.h"
#include "GlobalClock.hpp"
#include "UI.h"

PlateformerPaint::PlateformerPaint(sf::RenderWindow & window) : Screen(window)
{

}

std::unique_ptr<Screen> PlateformerPaint::execute()
{
	GlobalClock::lap();

	while (window_.isOpen())
	{
		sf::Vector2f mousePos = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
		sf::Event event{};
		while (window_.pollEvent(event))
		{
			auto res = gestionEvent(event);
			if (res)
				return std::move(*res);

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				if (UI::actionMouseClicked(mousePos))
					return nullptr;
			}
		}

		sf::Time elapsedTime = GlobalClock::lapTime();
		window_.clear();



		UI::update(mousePos);
		UI::draw(window_);

		window_.display();

		sf::sleep(sf::milliseconds(10));
	}
	return nullptr;
}
