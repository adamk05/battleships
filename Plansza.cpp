#include "Plansza.h"
Plansza::Plansza() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Pole p(i, j);
			this->plansza[i][j] = p;
		}
	}
}

void Plansza::setOwner(Gracz* gracz) {
	this->owner = gracz;
}

Gracz* Plansza::getOwner() {
	return this->owner;
}

Pole* Plansza::getSpecififcField(int x, int y) {
	return &this->plansza[x][y];
}