#pragma once
#include<SFML/Graphics.hpp>
class TextField
{
private:
	sf::Text text;
	sf::Font font;
public:
	TextField(int x, int y, std::string s, int size, sf::Color color = sf::Color::White);
	void drawTextField(sf::RenderWindow& window);
	void ustawKolor(sf::Color color);
	sf::String getS();
	void setS(sf::String s);
};



