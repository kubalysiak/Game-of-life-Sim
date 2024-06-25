#pragma once
#include <SFML/Graphics.hpp>

class SmallButton
{
private:
	sf::RectangleShape button;
	int width = 50;
	int height = 50;
public:
	SmallButton(int x, int y);
	void drawButton(sf::RenderWindow& window);
	void ustawKolor(sf::Color color);
	void ustawKolorRamki(sf::Color color);
	sf::FloatRect getGBounds();
};

