#pragma once
#include "FieldState.h"
#include "Game.h"
#include "Gracz.h"
#include "Plansza.h"
#include "Pole.h"

	void startGry(Gracz* g1, Gracz* g2, Plansza* p1, Plansza* p2);
	void ruch(Plansza* plansza, Gracz gracz);
	void rysujSwojaPlansze(Plansza plansza);
	void rysujPlanszePrzeciwnika(Plansza plansza);
	void rozstawStatki(Plansza* plansza);
	bool koniecGry(Plansza plansza);

