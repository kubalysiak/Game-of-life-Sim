#include "Button.h"

Button::Button(int x, int y) {
	button.setFillColor(sf::Color::Black);
	button.setOutlineColor(sf::Color::White);
	button.setOutlineThickness(1);
	button.setPosition(x, y);
	button.setSize(sf::Vector2f(width, height));
}
void Button::drawButton(sf::RenderWindow&window) {
	window.draw(button);
}
void Button::ustawKolor(sf::Color color) {
	button.setFillColor(color);
}
void Button::ustawKolorRamki(sf::Color color) {
	button.setOutlineColor(color);
}
sf::FloatRect Button::getGBounds() {
	return button.getGlobalBounds();
}