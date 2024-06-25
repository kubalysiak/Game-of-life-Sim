#pragma once
class Cell
{
private:
	bool alive;
public:
	Cell(); // konstruktor domyslny ustawiaj�cy stan kom�rki na martw�
	Cell(bool is_alive); //konstruktor ustawiaj�cy stan kom�rki na wybrany stan (martwa/zywa)
	bool IsAlive(); //sprawdzanie czy kom�rka jest �ywa
	void Toggle(); //prze��czanie stanu kom�rki
};

