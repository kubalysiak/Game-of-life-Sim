#include "Cell.h"

Cell::Cell() {
	alive = false;
}
Cell::Cell(bool is_alive) {
	alive = is_alive;
}
bool Cell::IsAlive() {
	return alive;
}
void Cell::Toggle() {
	alive = !alive;
}

