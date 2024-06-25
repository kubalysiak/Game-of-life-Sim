#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Button.h"
#include "TextField.h"
#include "Frame.h"
#include "Board.h"
#include "SmallButton.h"


class SimulationWindow
{
private:
	bool is_running = false;
	const int WINDOW_WIDTH = 1500;
	const int WINDOW_HEIGHT = 1000;
public:
	void DrawMenu();
	void DrawMainWindow();
	void ToggleSimulationState();
};

