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
	window.draw(getInstance().textTime_);
	window.draw(getInstance().textDate_);
}

void UI::loadSprites()
{
	getInstance().spriteBarre_.setTexture(RessourceLoader::getTexture("ui/desktop/barre_tache.png"));
	getInstance().spriteBarre_.setPosition(0, WINDOW_SIZE_Y - getInstance().spriteBarre_.getGlobalBounds().height);

	getInstance().textDate_.setFont(RessourceLoader::getFont("font/consola.ttf"));
	getInstance().textDate_.setCharacterSize(15);
	getInstance().textTime_.setFont(RessourceLoader::getFont("font/consola.ttf"));
	getInstance().textTime_.setCharacterSize(15);
}