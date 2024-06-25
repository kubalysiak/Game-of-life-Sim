#pragma once
#include <SFML/Graphics.hpp>
class Frame
{
private:
	sf::RectangleShape frame;
	int width = 300;
	int height = 100;
public:
	Frame(int x, int y);
	void drawFrame(sf::RenderWindow&window);
};

