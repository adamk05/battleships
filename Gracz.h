#pragma once
#include <iostream>
class Gracz
{
private:
	std::string name;
public:
	Gracz(std::string name);
	Gracz();

	std::string getName();
	void setName(std::string name);
};

