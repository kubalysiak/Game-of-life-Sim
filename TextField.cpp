#include "TextField.h"

TextField::TextField(int x, int y, std::string s, int size, sf::Color color) {
	font.loadFromFile("ARIAL.TTF");
	text.setFont(font);
	text.setString(s);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setPosition(x, y);
}
void TextField::drawTextField(sf::RenderWindow& window) {
	window.draw(text);
}
void TextField::ustawKolor(sf::Color color) {
	text.setFillColor(color);
}
sf::String TextField::getS() {
	return text.getString();
}
void TextField::setS(sf::String s) {
	text.setString(s);
}
