#include "SimulationWindow.h"


int board_size = 0;


void SimulationWindow::DrawMenu()
{
	sf::RenderWindow MenuWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Symulacja Gry w zycie - Menu", sf::Style::Close);
	
	sf::Event menuEvent;
	
	Frame EditSizeFrame(600, 300);
	TextField EditSize(720, 320, "3", 32);
	Button ConfirmButton(600, 500);
	TextField ConfirmButtonText(720, 520, "OK", 32);
	TextField ErrorText(620, 830, "Podaj liczbe z przedzialu < 3; 100 >!", 16, sf::Color::Transparent);
	TextField SizeInfo(550, 250, "Podaj rzadany rozmiar planszy <3 ; 100>", 24, sf::Color::Green);


	while (MenuWindow.isOpen())
	{
		while (MenuWindow.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::Closed)
			{
				exit(0);
			}
			if (menuEvent.type == sf::Event::TextEntered)
			{
				if (menuEvent.text.unicode == 8) //backspace
				{
					sf::String string = EditSize.getS();
					if (string.isEmpty()) { continue; }
					else
					{
						string.erase(string.getSize() - 1, 1);
						EditSize.setS(string);
					}
					
				}
				if (menuEvent.text.unicode >= 48 && menuEvent.text.unicode <= 57)
				{
					sf::String string = EditSize.getS();
					string += menuEvent.text.unicode;
					EditSize.setS(string);
				}
				
			}
			if (menuEvent.type == sf::Event::MouseMoved)
			{
				sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(MenuWindow));
				if (ConfirmButton.getGBounds().contains(sf::Vector2f(mousePos)))
				{
					ConfirmButton.ustawKolor(sf::Color::White);
					ConfirmButton.ustawKolorRamki(sf::Color::Red);
					ConfirmButtonText.ustawKolor(sf::Color::Black);
					
					
				}
				else
				{
					ConfirmButton.ustawKolor(sf::Color::Black);
					ConfirmButton.ustawKolorRamki(sf::Color::White);
					ConfirmButtonText.ustawKolor(sf::Color::White);
					
				}
			}
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2f mousePos2 = static_cast<sf::Vector2f>(sf::Mouse::getPosition(MenuWindow));
				if (ConfirmButton.getGBounds().contains(sf::Vector2f(mousePos2)))
				{
					sf::String tekst = EditSize.getS();
					
					if(tekst == "" || tekst.getSize() > 3)
					{
						ErrorText.ustawKolor(sf::Color::Red); 
					}
					else
					{
						std::string temp_str = EditSize.getS();
						board_size = std::stoi(temp_str);
						if (board_size < 3 || board_size > 100)
						{
							ErrorText.ustawKolor(sf::Color::Red);
						}
						else
						{
							MenuWindow.close();
							DrawMainWindow();
						}
					}
					
				}
				else
				{
					
					ErrorText.ustawKolor(sf::Color::Transparent);
				}
			}
		}
		MenuWindow.clear();
		EditSize.drawTextField(MenuWindow);
		EditSizeFrame.drawFrame(MenuWindow);
		ConfirmButton.drawButton(MenuWindow);
		ConfirmButtonText.drawTextField(MenuWindow);
		ErrorText.drawTextField(MenuWindow);
		SizeInfo.drawTextField(MenuWindow);
		MenuWindow.display();
	}
	
}
void SimulationWindow::DrawMainWindow()
{
	Board simul_board(board_size);
	sf::RenderWindow MainWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Symulacja Gry w zycie - Symulacja", sf::Style::Close);
	MainWindow.setFramerateLimit(30);

	sf::Event MainEvent;

	Button ToggleSimulation(1100, 20);
	TextField TSbtnText(1210, 40, "Start", 32);

	Button ClearBoard(1100, 130);
	TextField ClearBtnText(1190, 150, "Wyczysc", 32);

	Button Randomize(1100, 400);
	TextField RandomizebtnText(1180, 420, "Losuj pola", 32);

	Button Settings(1100, 800);
	TextField SettingsbtnText(1180, 820, "Ustawienia", 32);

	Frame RandomCounter(1100, 300);
	TextField RCText(1230, 320, "0", 32);

	TextField CounterInfo(1150, 550, "Predkosc symulacji:", 24);
	Frame SimSpeedFrame(1100, 600);
	TextField SSText(1180, 620, "1.000000", 32);
	SmallButton SSPlusCounter(1410, 590);
	TextField SSPText(1430, 600, "+", 20);
	SmallButton SSMinusCounter(1410, 660);
	TextField SSMText(1430, 670, "-", 20);

	sf::Clock clock;
	sf::Time interval = sf::seconds(1.0f);
	sf::Time elapsed = sf::Time::Zero;

	while (MainWindow.isOpen())
	{	
		
		if (is_running == true) {
			
			elapsed += clock.restart();
		}
		else {
			clock.restart();
		}
		
		

		while (MainWindow.pollEvent(MainEvent))
		{
			if (MainEvent.type == sf::Event::Closed)
			{
				exit(0);
			}
			if (MainEvent.type == sf::Event::MouseMoved)
			{
				sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(MainWindow)); //getPosition zwraca vector2i, wiec uzylem static_cast<vector2f>
				if (ToggleSimulation.getGBounds().contains(sf::Vector2f(mousePos)))
				{
					ToggleSimulation.ustawKolor(sf::Color::White);
					ToggleSimulation.ustawKolorRamki(sf::Color::Red);
					TSbtnText.ustawKolor(sf::Color::Black);
				}
				else if(Randomize.getGBounds().contains(sf::Vector2f(mousePos)))
				{
					Randomize.ustawKolor(sf::Color::White);
					Randomize.ustawKolorRamki(sf::Color::Red);
					RandomizebtnText.ustawKolor(sf::Color::Black);
				}
				else if (Settings.getGBounds().contains(sf::Vector2f(mousePos)))
				{
					Settings.ustawKolor(sf::Color::White);
					Settings.ustawKolorRamki(sf::Color::Red);
					SettingsbtnText.ustawKolor(sf::Color::Black);
				}
				else if (ClearBoard.getGBounds().contains(sf::Vector2f(mousePos)))
				{
					ClearBoard.ustawKolor(sf::Color::White);
					ClearBoard.ustawKolorRamki(sf::Color::Red);
					ClearBtnText.ustawKolor(sf::Color::Black);
				}
				else if (SSPlusCounter.getGBounds().contains(sf::Vector2f(mousePos)))
				{
					SSPlusCounter.ustawKolor(sf::Color::White);
					SSPText.ustawKolor(sf::Color::Black);
				}
				else if (SSMinusCounter.getGBounds().contains(sf::Vector2f(mousePos)))
				{
					SSMinusCounter.ustawKolor(sf::Color::White);
					SSMText.ustawKolor(sf::Color::Black);
				}
				else
				{
					ToggleSimulation.ustawKolor(sf::Color::Black);
					ToggleSimulation.ustawKolorRamki(sf::Color::White);
					TSbtnText.ustawKolor(sf::Color::White);

					Randomize.ustawKolor(sf::Color::Black);
					Randomize.ustawKolorRamki(sf::Color::White);
					RandomizebtnText.ustawKolor(sf::Color::White);

					Settings.ustawKolor(sf::Color::Black);
					Settings.ustawKolorRamki(sf::Color::White);
					SettingsbtnText.ustawKolor(sf::Color::White);

					ClearBoard.ustawKolor(sf::Color::Black);
					ClearBoard.ustawKolorRamki(sf::Color::White);
					ClearBtnText.ustawKolor(sf::Color::White);

					SSPlusCounter.ustawKolor(sf::Color::Black);
					SSPText.ustawKolor(sf::Color::White);

					SSMinusCounter.ustawKolor(sf::Color::Black);
					SSMText.ustawKolor(sf::Color::White);
				}
				
			}
			if (MainEvent.type == sf::Event::TextEntered)
			{
				if (MainEvent.text.unicode == 8) //backspace
				{
					sf::String string = RCText.getS();
					if (string.isEmpty()) { continue; }
					else
					{
						string.erase(string.getSize() - 1, 1);
						RCText.setS(string);
					}

				}
				if (MainEvent.text.unicode >= 48 && MainEvent.text.unicode <= 57)
				{
					sf::String string = RCText.getS();
					string += MainEvent.text.unicode;
					RCText.setS(string);
				}
			}
			if (MainEvent.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2f mousePos2 = static_cast<sf::Vector2f>(sf::Mouse::getPosition(MainWindow));
				
				int cell_size = 1000 / board_size;
				int x = mousePos2.x / cell_size;
				int y = mousePos2.y / cell_size;
				int ilosc = board_size * cell_size;
				if(mousePos2.x >= ilosc || mousePos2.y >= ilosc || mousePos2.x < 0 || mousePos2.y < 0)
				{
					if (Settings.getGBounds().contains(sf::Vector2f(mousePos2)))
					{
						is_running = false;
						MainWindow.close();
						DrawMenu();
						
					}
					else if (ToggleSimulation.getGBounds().contains(sf::Vector2f(mousePos2)))
					{
						if (is_running == false) 
						{
							elapsed = sf::Time::Zero;
							ToggleSimulationState();
							
						}
						else
						{	
							elapsed = sf::Time::Zero;
							ToggleSimulationState();
						}
						if (TSbtnText.getS() == "Start")
						{
							TSbtnText.setS("Stop");
						}
						else
						{
							TSbtnText.setS("Start");
						}
						
						
					}
					else if (ClearBoard.getGBounds().contains(sf::Vector2f(mousePos2)) && is_running==false)
					{
						simul_board.DeadBoard();
					}
					else if (Randomize.getGBounds().contains(sf::Vector2f(mousePos2)) && is_running==false)
					{
						sf::String temp = RCText.getS();
						std::string temp_s = temp;
						if (temp.isEmpty() || std::stoi(temp_s) <=0 || std::stoi(temp_s) > board_size * board_size)
						{
							continue;
						}
						else {
							simul_board.DeadBoard();
							int liczba_losowan = std::stoi(temp_s);
							simul_board.RandomizeBoard(liczba_losowan, board_size);
						}
						
					}
					else if (SSPlusCounter.getGBounds().contains(sf::Vector2f(mousePos2)))
					{
						sf::String tekst = SSText.getS();
						std::string tekst_s = tekst;
						double wartosc = std::stod(tekst_s);
						if (wartosc <= 0.1000000)
						{
							continue;
						}
						else if (wartosc==0.5)
						{
							wartosc -= 0.4;
							tekst_s = std::to_string(wartosc);
							SSText.setS(tekst_s);
							interval = sf::seconds((double)wartosc);
							elapsed = sf::seconds(0);
						}
						else
						{
							wartosc -= 0.5;
							tekst_s = std::to_string(wartosc);
							SSText.setS(tekst_s);
							interval = sf::seconds((double)wartosc);
							elapsed = sf::seconds(0);
						}
					}
					else if (SSMinusCounter.getGBounds().contains(sf::Vector2f(mousePos2)))
					{
						sf::String tekst = SSText.getS();
						std::string tekst_s = tekst;
						double wartosc = std::stod(tekst_s);
						if (wartosc >= 2)
						{
							continue;
						}
						else if (wartosc == 0.1)
						{
							wartosc += 0.4;
							tekst_s = std::to_string(wartosc);
							SSText.setS(tekst_s);
							interval = sf::seconds((double)wartosc);
							sf::seconds(0);
						}
						else
						{
							wartosc += 0.5;
							tekst_s = std::to_string(wartosc);
							SSText.setS(tekst_s);
							interval = sf::seconds((double)wartosc);
							sf::seconds(0);
						}
					}
					else
					{
						continue;
					}
				}
				else 
				{
					simul_board.ToggleCell(x, y);
				}
				
					
			}
			
		}
		if (elapsed >= interval)
		{
			if (is_running)
			{
				elapsed -= interval;
				MainWindow.clear();
				simul_board.DrawBoard(MainWindow);
				simul_board.UpdateBoard();
				ToggleSimulation.drawButton(MainWindow);
				TSbtnText.drawTextField(MainWindow);
				ClearBoard.drawButton(MainWindow);
				ClearBtnText.drawTextField(MainWindow);
				Randomize.drawButton(MainWindow);
				RandomizebtnText.drawTextField(MainWindow);
				Settings.drawButton(MainWindow);
				SettingsbtnText.drawTextField(MainWindow);
				RandomCounter.drawFrame(MainWindow);
				SSPlusCounter.drawButton(MainWindow);
				SSMinusCounter.drawButton(MainWindow);
				RCText.drawTextField(MainWindow);
				SSPText.drawTextField(MainWindow);
				SSMText.drawTextField(MainWindow);
				SimSpeedFrame.drawFrame(MainWindow);
				SSText.drawTextField(MainWindow);
				CounterInfo.drawTextField(MainWindow);
				MainWindow.display();
			}
			else
			{
				MainWindow.clear();
				simul_board.DrawBoard(MainWindow);
				ToggleSimulation.drawButton(MainWindow);
				TSbtnText.drawTextField(MainWindow);
				ClearBoard.drawButton(MainWindow);
				ClearBtnText.drawTextField(MainWindow);
				Randomize.drawButton(MainWindow);
				RandomizebtnText.drawTextField(MainWindow);
				Settings.drawButton(MainWindow);
				SettingsbtnText.drawTextField(MainWindow);
				RandomCounter.drawFrame(MainWindow);
				SSPlusCounter.drawButton(MainWindow);
				SSMinusCounter.drawButton(MainWindow);
				RCText.drawTextField(MainWindow);
				SSPText.drawTextField(MainWindow);
				SSMText.drawTextField(MainWindow);
				SimSpeedFrame.drawFrame(MainWindow);
				SSText.drawTextField(MainWindow);
				CounterInfo.drawTextField(MainWindow);
				MainWindow.display();
				
			}
		}
		else
		{
			
			
			MainWindow.clear();
			simul_board.DrawBoard(MainWindow);
			ToggleSimulation.drawButton(MainWindow);
			TSbtnText.drawTextField(MainWindow);
			ClearBoard.drawButton(MainWindow);
			ClearBtnText.drawTextField(MainWindow);
			Randomize.drawButton(MainWindow);
			RandomizebtnText.drawTextField(MainWindow);
			Settings.drawButton(MainWindow);
			SettingsbtnText.drawTextField(MainWindow);
			RandomCounter.drawFrame(MainWindow);
			SSPlusCounter.drawButton(MainWindow);
			SSMinusCounter.drawButton(MainWindow);
			RCText.drawTextField(MainWindow);
			SSPText.drawTextField(MainWindow);
			SSMText.drawTextField(MainWindow);
			SimSpeedFrame.drawFrame(MainWindow);
			SSText.drawTextField(MainWindow);
			CounterInfo.drawTextField(MainWindow);
			
			MainWindow.display();

			
		}
		
	}
}

void SimulationWindow::ToggleSimulationState()
{
	is_running = !is_running;
}
