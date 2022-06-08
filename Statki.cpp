#include <iostream>
#include "Game.h"
#include "Pole.h"
#include "Gracz.h"
#include "FieldState.h"
#include "Plansza.h"
#include "Kierunek.h"

using namespace std;

int main()
{
    Gracz gracz1;
    Gracz gracz2;
    Gracz* aktualnyGracz = &gracz1;//wskaźnik na gracza, który będzie wykonywał ruch
    Gracz* zwyciezca;
    Plansza plansza1;
    Plansza plansza2;
    Plansza* aktualnaPlansza = &plansza2; //wskaźnik na planszę, na którą będzie wykonywany strzał
    bool b_koniecGry = false;

    startGry(&gracz1, &gracz2, &plansza1, &plansza2);
    rozstawStatki(&plansza1);
    rozstawStatki(&plansza2);
    while (!b_koniecGry) {
        //w zależności od tego, który gracz ma ruch, aktualna plansza się zmienia
        if (aktualnyGracz == &gracz1)
            aktualnaPlansza = &plansza2;
        else
            aktualnaPlansza = &plansza1;
        ruch(aktualnaPlansza, *aktualnyGracz);
        b_koniecGry = koniecGry(*aktualnaPlansza);
        if (koniecGry)
            zwyciezca = aktualnyGracz;
        if (aktualnyGracz == &gracz1)
            aktualnyGracz = &gracz2;
        else
            aktualnyGracz = &gracz1;
    }
    cout << "Wygral " << aktualnyGracz->getName();

}
