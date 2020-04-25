#pragma once
#include "pacient.h"

class Copil: public Pacient{
	std::string antecedentefamilie;
	std::string numeMama;
	std::string numeTata;
	std::string dataProteinaC;
	double proteinaC;
public:
	Copil(std::string = "", std::string = "", int = 0, double = 0, double = 0, std::string = "", std::string = "", std::string = "", std::string = "", std::string = "", std::string = "", double = 0);
	Copil(const Copil &);
	Copil& operator=(const Copil&);
	~Copil();

	virtual void citire();
	virtual void afisare();
	virtual std::string gradRiscCardiovascular();
	std::string getType();
};