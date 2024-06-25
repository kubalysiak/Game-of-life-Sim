#pragma once
#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::RectangleShape button;
	int width = 300;
	int height = 100;
public:
	Button(int x, int y);
	void drawButton(sf::RenderWindow&window);
	void ustawKolor(sf::Color color);
	void ustawKolorRamki(sf::Color color);
	sf::FloatRect getGBounds();
};

