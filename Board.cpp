#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <set>
#include <ctime>



Board::Board(int N) {
	board.resize(N);
	for (int i = 0; i < N; i++) {
		board[i].resize(N);
	}
	size = N;
}
int Board::GetBoardSize() {
	return size;
}
void Board::SetCell(int x, int y, bool is_alive) {
	board[x][y] = is_alive;
}
Cell Board::GetCell(int x, int y) {
	return board[x][y];
}
int Board::CountAliveNeighbours(int x, int y) {
	int counter = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0)
			{
				continue; //pomijamy sam¹ siebie
			}
			int row = i + x;
			int col = j + y;
			if (row < 0 || row >= size || col < 0 || col >= size) //sprawdzamy czy sprawdzane pole znajduje siê poza granicami planszy
			{
				continue; 
			}
			if (board[row][col].IsAlive())
			{
				counter++;
			}
		}
	}
	return counter;
}
void Board::PrintBoard() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j].IsAlive()) {
				std::cout << "1";
			}
			else {
				std::cout << "0";
			}
		}
		std::cout << "\n";
	}
}
void Board::ToggleCell(int x, int y) {
	board[x][y].Toggle();
}
void Board::UpdateBoard() {
	Board temp_board(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int AliveNeighbours = CountAliveNeighbours(i, j);
			if (board[i][j].IsAlive())
			{
				if (AliveNeighbours == 2 || AliveNeighbours == 3) //je¿eli ¿yje i ma 2 lub 3 zyj¹cych s¹siadów to prze¿ywa, inaczej ginie poprzez zbyt ma³¹ iloœæ ¿ywych s¹siadów lub poprzez przeludnienie
				{
					temp_board.SetCell(i, j, true);
				}
				else {
					temp_board.SetCell(i, j, false);
				}
			}
			else
			{
				if (AliveNeighbours == 3) //je¿eli komórka jest martwa i ma 3 ¿ywych s¹siadów to o¿ywa
				{
					temp_board.SetCell(i, j, true);
				}
				else
				{
					temp_board.SetCell(i, j, false);	//inaczej pozostaje martwa
				}
			}
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = temp_board.GetCell(i,j);
		}
	}
	
}
void Board::DrawBoard(sf::RenderWindow& window) {
	int cell_size = 1000 / size;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			sf::Color color;
			if (board[i][j].IsAlive()) {
				color = sf::Color::White;
			}
			else {
				color = sf::Color::Black;
			}
			sf::RectangleShape rectangle(sf::Vector2f(cell_size, cell_size));
			rectangle.setPosition(i * cell_size, j * cell_size);
			rectangle.setOutlineThickness(1);
			rectangle.setOutlineColor(sf::Color{ 55,55,55 });
			rectangle.setFillColor(color);
			window.draw(rectangle);
		}
	}
}
void Board::DeadBoard() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			SetCell(i, j, false);
		}
	}
}
void Board::RandomizeBoard(int n, int size) {
	srand(time(NULL));
	std::set<std::pair<int, int>> wylosowane; //u¿y³em set bo przechowuje unikalne wartoœci - przez co funkcja losuje pary pól do momentu a¿ zrówna siê z podan¹ iloœci¹ n pól do wylosowania

	while (wylosowane.size() < n)
	{
		int x = rand() % size;
		int y = rand() % size;
		wylosowane.insert({ x,y });
	}
	
	for(std::pair<int,int>para:wylosowane){
		int x = para.first;
		int y = para.second;
		SetCell(x, y, true);
	}
	

}
