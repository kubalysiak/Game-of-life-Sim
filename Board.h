#pragma once
#include "Cell.h"
#include "SFML/Graphics.hpp"
#include <vector>

class Board
{
public:
	Board(int N); //konstruktor tworz�cy tablic� dwuwymiarow� o rozmiarze N x N
	
	int GetBoardSize(); // pobranie rozmiaru tablicy 
	void PrintBoard(); 

	void SetCell(int x, int y, bool is_alive); //ustawienie kom�rki x,y na is_alive(true/false)
	void ToggleCell(int x, int y); //prze��czanie kom�rki (�ywa/martwa)
	Cell GetCell(int x, int y); //pobranie danej kom�rki(x,y)
	
	int CountAliveNeighbours(int x, int y); //zliczanie �ywych s�siad�w

	void UpdateBoard(); //Od�wie�enie planszy - przej�cie do nast�pnego stanu
	void DrawBoard(sf::RenderWindow& window);

	void DeadBoard(); //ustawienie pol planszy na martwe
	void RandomizeBoard(int n, int size); //wylosowanie n �ywych p�l
	

private:
	std::vector<std::vector<Cell>> board; 
	int size;
};
