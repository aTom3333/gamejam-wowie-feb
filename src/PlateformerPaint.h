#ifndef PLATEFORMER_PAINT_H
#define PLATEFORMER_PAINT_H

#include "Screen.hpp"

class PlateformerPaint : public Screen
{
	public:
		PlateformerPaint(sf::RenderWindow& window);
		std::unique_ptr<Screen> execute() override;
	private:
};

#endif