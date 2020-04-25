#pragma once
#include "pacient.h"

class Adultpeste40: public Pacient{
	std::string fumator;
	std::string sedentarism;
public:
	Adultpeste40(std::string = "", std::string = "", int = 0, double = 0, double = 0, std::string = "", std::string = "", std::string = "", std::string = "");
	Adultpeste40(const Adultpeste40 &);
	Adultpeste40& operator=(const Adultpeste40&);
	~Adultpeste40();

	virtual void citire();
	virtual void afisare();
	virtual std::string gradRiscCardiovascular();
	std::string getType();
};