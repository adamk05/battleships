#include "Gracz.h"
Gracz::Gracz(){}

Gracz::Gracz(std::string name) {
	this->name = name;
}

std::string Gracz::getName() {
	return this->name;
}

void Gracz::setName(std::string name) {
	this->name = name;
}