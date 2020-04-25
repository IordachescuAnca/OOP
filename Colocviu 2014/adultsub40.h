#pragma once
#include "pacient.h"

class Adultsub40: public Pacient{
public:
	Adultsub40(std::string = "", std::string = "", int = 0, double = 0, double = 0, std::string = "", std::string = "");
	Adultsub40(const Adultsub40 &);
	Adultsub40& operator=(const Adultsub40&);
	~Adultsub40();

	virtual void citire();
	virtual void afisare();
	virtual std::string gradRiscCardiovascular();
	std::string getType();
};