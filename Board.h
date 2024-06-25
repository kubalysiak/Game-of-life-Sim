#pragma once
#include "Cell.h"
#include "SFML/Graphics.hpp"
#include <vector>

class Board
{
public:
	Board(int N); //konstruktor tworz¹cy tablicê dwuwymiarow¹ o rozmiarze N x N
	
	int GetBoardSize(); // pobranie rozmiaru tablicy 
	void PrintBoard(); 

	void SetCell(int x, int y, bool is_alive); //ustawienie komórki x,y na is_alive(true/false)
	void ToggleCell(int x, int y); //prze³¹czanie komórki (¿ywa/martwa)
	Cell GetCell(int x, int y); //pobranie danej komórki(x,y)
	
	int CountAliveNeighbours(int x, int y); //zliczanie ¿ywych s¹siadów

	void UpdateBoard(); //Odœwie¿enie planszy - przejœcie do nastêpnego stanu
	void DrawBoard(sf::RenderWindow& window);

	void DeadBoard(); //ustawienie pol planszy na martwe
	void RandomizeBoard(int n, int size); //wylosowanie n ¿ywych pól
	

private:
	std::vector<std::vector<Cell>> board; 
	int size;
};
