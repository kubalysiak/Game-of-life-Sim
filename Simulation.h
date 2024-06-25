#pragma once
#include <SFML/Graphics.hpp>

class Simulation
{
public:
	Simulation();
	~Simulation();

	void setup();
	void run();

private:
	const int _WINDOW_WIDTH = 1500;
	const int _WINDOW_HEIGHT = 1000;
	const std::string _WINDOW_NAME = "Symulacja gry w ¿ycie";

	sf::RenderWindow * _mainWindow;
};

