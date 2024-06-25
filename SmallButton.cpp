#include "SmallButton.h"

SmallButton::SmallButton(int x, int y) {
	button.setFillColor(sf::Color::Black);
	button.setOutlineColor(sf::Color::Red);
	button.setOutlineThickness(1);
	button.setPosition(x, y);
	button.setSize(sf::Vector2f(width, height));
}
void SmallButton::drawButton(sf::RenderWindow& window) {
	window.draw(button);
}
void SmallButton::ustawKolor(sf::Color color) {
	button.setFillColor(color);
}
void SmallButton::ustawKolorRamki(sf::Color color) {
	button.setOutlineColor(color);
}
sf::FloatRect SmallButton::getGBounds() {
	return button.getGlobalBounds();
}