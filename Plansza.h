#pragma once
#include "Pole.h"
#include "Gracz.h"
class Plansza
{
public:
	Pole plansza[10][10];
	Gracz* owner;

	Plansza();

	void setOwner(Gracz* gracz);
	Gracz* getOwner();

	Pole* getSpecififcField(int x, int y);
};

