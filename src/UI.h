#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>

class UI {
	private:
		UI() = default;
		sf::Sprite spriteBarre_;
		sf::Text textDate_;
		sf::Text textTime_;
	public:
		UI(UI const&) = delete;
		UI(UI&&) = delete;
		UI& operator=(UI const&) = delete;
		UI& operator=(UI&&) = delete;

		static UI& getInstance();
		static void draw(sf::RenderWindow &window);
		static void loadSprites();
};


#endif
