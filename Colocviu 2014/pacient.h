#pragma once
#include<string>

class Pacient{
private:
	static int contor;
protected:
	std::string nume;
	std::string prenume;
	int varsta;
	double colesterol;
	double tensiuneArteriala;
	std::string datacolesterol;
	std::string datatensiune;
	int id;
public:
	Pacient(std::string = "", std::string = "", int = 0, double = 0, double = 0, std::string = "", std::string = "");
	Pacient(const Pacient &);
	Pacient& operator=(const Pacient&);
	virtual ~Pacient();

	virtual void citire() = 0;
	virtual void afisare() = 0;
	virtual std::string gradRiscCardiovascular() = 0;
	virtual std::string getType() = 0;

	int getId() const;
	std::string getNume() const;

};