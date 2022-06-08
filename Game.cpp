#include "FieldState.h"
#include "Game.h"
#include "Gracz.h"
#include "Plansza.h"
#include "Pole.h"
#include "Kierunek.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void startGry(Gracz* g1, Gracz* g2, Plansza* p1, Plansza* p2) {
	string name1, name2;
	cout << "Imie gracza 1: \n";
	cin >> name1;
	cout << "Imie gracza 2: \n";
	cin >> name2;
	g1->setName(name1);
	g2->setName(name2);

	p1->setOwner(g1);
	p2->setOwner(g2);
}

void ruch(Plansza* plansza, Gracz gracz) {
	cout << "Strzela " << gracz.getName() << "\n";
	char z;
	int y, x;
	rysujPlanszePrzeciwnika(*plansza);
	while (true) {
		cout << "Kolumna: \n";
		cin >> z;
		z = toupper(z);
		cout << "Rzad: \n";
		cin >> y;
		y--;
		x = ((int)z - 65);
		if (y >= 0 && y < 10 && x >= 0 && x < 10) {
			if (plansza->getSpecififcField(y, x)->isShooted()) {
				cout << "juz tu strzelales \n";
			}
			else
				break;
		}
		else
			cout << "Nieprawidlowe dane\n";
	}
	
	if (plansza->getSpecififcField(y, x)->getFieldState() == field_empty) {
		cout << "Pudlo \n";
	}
	else {
		cout << "Trafiony \n";
	}
	
	plansza->getSpecififcField(y, x)->setShooted();
}

void rysujSwojaPlansze(Plansza plansza) {
	cout << "   ";
	int rzedy = 1;
	for (int i = 0; i < 10; i++) {
		cout << (char)(65 + i) << " | ";
	}
	cout << "\n   -   -   -   -   -   -   -   -   -   -\n";
	for (int j = 0; j < 10; j++) {
		cout << rzedy <<"| ";
		for (int k = 0; k < 10; k++) {
			if (plansza.getSpecififcField(j, k)->getFieldState() == field_empty)
				cout << "O | ";
			else
				cout << "X | ";
			
		}
		cout << "\n   -   -   -   -   -   -   -   -   -   -\n";
		rzedy++;
	}
}

void rysujPlanszePrzeciwnika(Plansza plansza) {
	cout << "   ";
	int rzedy = 1;
	for (int i = 0; i < 10; i++) {
		cout << (char)(65 + i)<<" | ";
	}
	cout << "\n   -   -   -   -   -   -   -   -   -   -\n";
	for (int j = 0; j < 10; j++) {
		cout << rzedy << "| ";
		for (int k = 0; k < 10; k++) {
			if (!plansza.getSpecififcField(j, k)->isShooted()) {
				cout << "S | ";
			}
			else {
				if (plansza.getSpecififcField(j, k)->getFieldState() == field_empty)
					cout << "O | ";
				else
					cout << "X | ";
			}

		}
		cout << "\n   -   -   -   -   -   -   -   -   -   -\n";
		rzedy++;
	}
}

void rozstawStatki(Plansza* plansza) {
	vector<Pole*> polaStatku;
	int dlugosc;
	char cy;
	string cx;
	bool incorrect;
	int y, x;
	Kierunek kierunek;
	int n_kierunek;

	cout << "Rozstawia " << plansza->getOwner()->getName() << endl;
		for (int i = 1; i <= 5; i++) {
			incorrect = true;
			rysujSwojaPlansze(*plansza);
			switch (i) {
			case 1: {
				cout << "piecioplatowiec \n";
				dlugosc = 5;
				break;
			}
			case 2: {
				cout << "czteroplatowiec \n";
				dlugosc = 4;
				break;
			}
			case 3: {
				cout << "trojplatowiec \n";
				dlugosc = 3;
				break;
			}
			case 4: {
				cout << "dwuplatowiec \n";
				dlugosc = 2;
				break;
			}
			case 5: {
				cout << "jednoplatowiec \n";
				dlugosc = 1;
				break;
			}
			default: {
				cout << "statek \n";
				dlugosc = 0;
				break;
			}
			}

			while (incorrect) {
				cout << "Kolumna (poczatek statku): \n";
				cin >> cy;
				cout << "Rzad (poczatek statku):\n";
				cin >> cx;
				cy = toupper(cy);
				x = stoi(cx) - 1;
				y = ((int)cy - 65);

				if (y < 0 || y >= 10 || x >= 10 || x < 0) {
					cout << "Niepoprawne pole\n";
					continue;
				}
				if (dlugosc == 1) {
					if (plansza->getSpecififcField(x, y)->getFieldState() == field_ship) {
						cout << "Tu nie mozna umiescic tego statku!\n";
					}
					else if (x + 1 < 10 && plansza->getSpecififcField(x + 1, y)->getFieldState() == field_ship) {
						cout << "Tu nie mozna umiescic tego statku!\n";
					}
					else if (x - 1 >= 0 && plansza->getSpecififcField(x - 1, y)->getFieldState() == field_ship) {
						cout << "Tu nie mozna umiescic tego statku!\n";
					}
					else if (y + 1 < 10 && plansza->getSpecififcField(x, y + 1)->getFieldState() == field_ship) {
						cout << "Tu nie mozna umiescic tego statku!\n";
					}
					else if(y - 1 >= 0 && plansza->getSpecififcField(x, y - 1)->getFieldState() == field_ship) {
						cout << "Tu nie mozna umiescic tego statku!\n";
					}
					else {
						polaStatku.push_back(plansza->getSpecififcField(x, y));
					}
				}
				else {
					cout << "Kierunek: (1->gora, 2->prawo, 3->dol, 4->lewo) \n";
					cin >> n_kierunek;
					switch (n_kierunek)
					{
					case 1: {
						kierunek = gora;
						break;
					}
					case 2: {
						kierunek = prawo;
						break;
					}
					case 3: {
						kierunek = dol;
						break;
					}
					case 4: {
						kierunek = lewo;
						break;
					}
					default: {
						kierunek = gora;
						break;
					}
					}

					switch (kierunek) {
					case gora: {
						//sprawdzenie czy statek nie wykracza poza planszê
						if (x - dlugosc < 0) {
							cout << "Tu nie mozna umiescic tego statku!\n";
							goto wyjdz;
						}
						//sprawdzenie czy na polach statku i polach s¹siaduj¹cych nie znajduje siê ju¿ statek
						for (int j = 0; j < dlugosc; j++) {
							//konkretne pole
							if (plansza->getSpecififcField(x - j, y)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole powy¿ej
							else if (y + 1 < 10 && plansza->getSpecififcField(x - j, y + 1)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole ponie¿ej
							else if (y - 1 >= 0 && plansza->getSpecififcField(x - j, y - 1)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole na prawo
							else if (x + 1 - j < 10 && plansza->getSpecififcField(x + 1 - j, y)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole na lewo
							else if (x - 1 - j >= 0 && plansza->getSpecififcField(x - 1 - j, y)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//jeœli dooko³a nie ma statku dodajemy pole do wektora
							else {
								polaStatku.push_back(plansza->getSpecififcField(x - j, y));
							}
						}

						break;
					}
					case prawo: {
						//sprawdzenie czy statek nie wykracza poza planszê
						if (y + dlugosc > 9) {
							cout << "Tu nie mozna umiescic tego statku!\n";
							goto wyjdz;
						}
						//sprawdzenie czy na polach statku i polach s¹siaduj¹cych nie znajduje siê ju¿ statek
						for (int j = 0; j < dlugosc; j++) {
							//konkretne pole
							if (plansza->getSpecififcField(x, y + j)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole powy¿ej
							else if (y + j + 1 < 10 && plansza->getSpecififcField(x, y + j + 1)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole ponie¿ej
							else if (y + j - 1 >= 0 && plansza->getSpecififcField(x, y + j - 1)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole na prawo
							else if (x + 1 < 10 && plansza->getSpecififcField(x + 1, y + j)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole na lewo
							else if (x - 1 >= 0 && plansza->getSpecififcField(x - 1, y + j)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//jeœli dooko³a nie ma statku dodajemy pole do wektora
							else {
								polaStatku.push_back(plansza->getSpecififcField(x, y + j));
							}
						}
						break;
					}
					case dol: {
						//sprawdzenie czy statek nie wykracza poza planszê
						if (x + dlugosc > 9) {
							cout << "Tu nie mozna umiescic tego statku!\n";
							goto wyjdz;
						}
						//sprawdzenie czy na polach statku i polach s¹siaduj¹cych nie znajduje siê ju¿ statek
						for (int j = 0; j < dlugosc; j++) {
							//konkretne pole
							if (plansza->getSpecififcField(x + j, y)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole powy¿ej
							else if (y + 1 < 10 && plansza->getSpecififcField(x + j, y + 1)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole ponie¿ej
							else if (y - 1 >= 0 && plansza->getSpecififcField(x + j, y - 1)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole na prawo
							else if (x + 1 + j < 10 && plansza->getSpecififcField(x + 1 + j, y)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole na lewo
							else if (x - 1 >= 0 && plansza->getSpecififcField(x - 1 + j, y)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//jeœli dooko³a nie ma statku dodajemy pole do wektora
							else {
								polaStatku.push_back(plansza->getSpecififcField(x + j, y));
							}
						}

						break;
					}
					case lewo: {
						//sprawdzenie czy statek nie wykracza poza planszê
						if (y - dlugosc < 0) {
							cout << "Tu nie mozna umiescic tego statku!\n";
							goto wyjdz;
						}
						//sprawdzenie czy na polach statku i polach s¹siaduj¹cych nie znajduje siê ju¿ statek
						for (int j = 0; j < dlugosc; j++) {
							//konkretne pole
							if (plansza->getSpecififcField(x, y - j)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole powy¿ej
							else if (y - j + 1 < 10 && plansza->getSpecififcField(x, y - j + 1)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole ponie¿ej
							else if (y - j - 1 >= 0 && plansza->getSpecififcField(x, y - j - 1)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole na prawo
							else if (x + 1 < 10 && plansza->getSpecififcField(x + 1, y - j)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//pole na lewo
							else if (x - 1 < 10 && plansza->getSpecififcField(x - 1, y - j)->getFieldState() == field_ship) {
								cout << "Tu nie mozna umiescic tego statku!\n";
								goto wyjdz;
							}
							//jeœli dooko³a nie ma statku dodajemy pole do wektora
							else {
								polaStatku.push_back(plansza->getSpecififcField(x, y - j));
							}
						}
						break;

					wyjdz:
						break;


					}
					}
				}

					if (polaStatku.size() == dlugosc) {
						for (int l = 0; l < dlugosc; l++) {
							Pole* akt_pole = polaStatku.at(l);
							akt_pole->setFieldState(field_ship);
						}
						incorrect = false;

					}
					polaStatku.clear();
				
			}
		}
		
	
}

bool koniecGry(Plansza plansza) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (plansza.getSpecififcField(i, j)->getFieldState() == field_ship && !plansza.getSpecififcField(i, j)->isShooted())
				return false;
		}
	}
	return true;
}