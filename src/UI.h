#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>

class UI {
	private:
		UI() = default;
		sf::Sprite spriteBarre_;
		sf::Sprite spriteButton_;
		sf::Sprite spriteMenu_;
		sf::Text textDate_;
		sf::Text textTime_;
		bool displayed_ = false;
	public:
		UI(UI const&) = delete;
		UI(UI&&) = delete;
		UI& operator=(UI const&) = delete;
		UI& operator=(UI&&) = delete;

		static UI& getInstance();
		static void draw(sf::RenderWindow &window);
		static void actionMouseClicked(sf::Vector2f pos);
		static void loadSprites();
};


#endif
