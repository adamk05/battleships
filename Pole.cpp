#include "Pole.h"

Pole::Pole() {
	this->fieldState = field_empty;
}

Pole::Pole(int x, int y) {
	this->x = x;
	this->y = y;
	this->fieldState = field_empty;
	this->shooted = false;
}

int Pole::getX() {
	return this->x;
}

void Pole::setX(int x) {
	this->x = x;
}

int Pole::getY() {
	return this->y;
}

void Pole::setY(int y) {
	this->y = y;
}

FieldState Pole::getFieldState() {
	return this->fieldState;
}

void Pole::setFieldState(FieldState fs) {
	this->fieldState = fs;
}

bool Pole::isShooted() {
	return this->shooted;
}

void Pole::setShooted() {
	this->shooted = true;
}
