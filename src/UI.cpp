#include "UI.h"
#include "RessourceLoader.hpp"
#include "constantes.hpp"

#include <ctime>
#include <string>

UI & UI::getInstance()
{
	static UI instance;
	return instance;
}

void UI::draw(sf::RenderWindow & window)
{
	std::time_t t = std::time(0);
	std::tm now;
	localtime_s(&now, &t);

	std::string strTime = "";
	if (now.tm_hour < 10) strTime += "0";
	strTime += std::to_string(now.tm_hour) + ":";
	if (now.tm_min < 10) strTime += "0";
	strTime += std::to_string(now.tm_min);

	getInstance().textTime_.setString(strTime);
	getInstance().textTime_.setPosition(1150 - getInstance().textTime_.getGlobalBounds().width/2, 685);

	std::string strDate = "";
	if (now.tm_mday < 10) strDate += "0";
	strDate += std::to_string(now.tm_mday) + "/";
	if (now.tm_mon < 10) strDate += "0";
	strDate += std::to_string(now.tm_mon) + "/";
	strDate += std::to_string(now.tm_year + 1900);

	getInstance().textDate_.setString(strDate);
	getInstance().textDate_.setPosition(1150 - getInstance().textDate_.getGlobalBounds().width/2, 700);

	window.draw(getInstance().spriteBarre_);
	window.draw(getInstance().spriteButton_);
	if (getInstance().displayed_) 
	{
		window.draw(getInstance().spriteMenu_);
		window.draw(getInstance().spriteQuit_);
	}
	window.draw(getInstance().textTime_);
	window.draw(getInstance().textDate_);
}

bool UI::actionMouseClicked(sf::Vector2f pos)
{
	if (getInstance().spriteButton_.getGlobalBounds().contains(pos))
		getInstance().displayed_ = !getInstance().displayed_;
	else if (getInstance().displayed_)
	{
		if(getInstance().spriteQuit_.getGlobalBounds().contains(pos))
			return true;
	}
	else if(!getInstance().spriteMenu_.getGlobalBounds().contains(pos))
		getInstance().displayed_ = false;

	return false;
}

void UI::loadSprites()
{
	getInstance().spriteBarre_.setTexture(RessourceLoader::getTexture("ui/desktop/barre_tache.png"));
	getInstance().spriteBarre_.setPosition(0, WINDOW_SIZE_Y - getInstance().spriteBarre_.getGlobalBounds().height);

	getInstance().spriteButton_.setTexture(RessourceLoader::getTexture("ui/desktop/start_button.png"));
	getInstance().spriteButton_.setPosition(0, WINDOW_SIZE_Y - getInstance().spriteButton_.getGlobalBounds().height);

	getInstance().spriteMenu_.setTexture(RessourceLoader::getTexture("ui/desktop/menu_demarrer.png"));
	getInstance().spriteMenu_.setPosition(0, WINDOW_SIZE_Y - getInstance().spriteButton_.getGlobalBounds().height - getInstance().spriteMenu_.getGlobalBounds().height);

	getInstance().spriteQuit_.setTexture(RessourceLoader::getTexture("ui/desktop/quit_button.png"));
	getInstance().spriteQuit_.setPosition(60, WINDOW_SIZE_Y - 1.8*getInstance().spriteButton_.getGlobalBounds().height);


	getInstance().textDate_.setFont(RessourceLoader::getFont("font/consola.ttf"));
	getInstance().textDate_.setCharacterSize(15);
	getInstance().textTime_.setFont(RessourceLoader::getFont("font/consola.ttf"));
	getInstance().textTime_.setCharacterSize(15);
}
