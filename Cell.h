#pragma once
class Cell
{
private:
	bool alive;
public:
	Cell(); // konstruktor domyslny ustawiaj¹cy stan komórki na martw¹
	Cell(bool is_alive); //konstruktor ustawiaj¹cy stan komórki na wybrany stan (martwa/zywa)
	bool IsAlive(); //sprawdzanie czy komórka jest ¿ywa
	void Toggle(); //prze³¹czanie stanu komórki
};

