#pragma once
#include "FieldState.h"
class Pole
{
private:
	int x;
	int y;
	FieldState fieldState;
	bool shooted;
public:
	Pole();
	Pole(int x, int y);

	int getX();
	void setX(int x);

	int getY();
	void setY(int y);

	FieldState getFieldState();
	void setFieldState(FieldState fs);

	bool isShooted();
	void setShooted();
};

