#ifndef UI_H
#define UI_H

#include <vector>
#include <SFML/Graphics.hpp>

class UI {
	private:
		UI() = default;
		sf::Sprite spriteBarre_;
		sf::Sprite spriteButton_;
		sf::Sprite spriteMenu_;
		sf::Sprite spriteQuit_;
		std::vector<sf::Sprite> spritesItem_;
		sf::Text textDate_;
		sf::Text textTime_;
		sf::RectangleShape highlight_;

		bool displayed_ = false;
		int unlockedLevel_ = 4;
	public:
		UI(UI const&) = delete;
		UI(UI&&) = delete;
		UI& operator=(UI const&) = delete;
		UI& operator=(UI&&) = delete;

		static UI& getInstance();
		static void update(sf::Vector2f pos);
		static void draw(sf::RenderWindow &window);
		static bool actionMouseClicked(sf::Vector2f pos);
		static void loadSprites();
};


#endif
