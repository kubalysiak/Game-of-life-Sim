#include "Frame.h"

Frame::Frame(int x, int y) {
	frame.setFillColor(sf::Color::Transparent);
	frame.setOutlineColor(sf::Color::White);
	frame.setOutlineThickness(1);
	frame.setPosition(x, y);
	frame.setSize(sf::Vector2f(width, height));
}
void Frame::drawFrame(sf::RenderWindow&window) {
	window.draw(frame);
}