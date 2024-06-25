#include "Simulation.h"

Simulation::Simulation() {

}

Simulation::~Simulation() {

}

void Simulation::setup() {
	_mainWindow = new sf::RenderWindow{ sf::VideoMode{_WINDOW_WIDTH, _WINDOW_HEIGHT}, _WINDOW_NAME, sf::Style::Close };

}


void Simulation::run() {

}