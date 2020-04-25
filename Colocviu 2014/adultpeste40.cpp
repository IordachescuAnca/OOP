#include "adultpeste40.h"
#include <iostream>

Adultpeste40::Adultpeste40(std::string nume, std::string prenume, int varsta, double colesterol, double tensiuneArteriala, std::string datacolesterol, std::string datatensiune, std::string fumator, std::string sedentarism): Pacient(nume, prenume, varsta, colesterol, tensiuneArteriala, datacolesterol, datatensiune){
	this->fumator = fumator;
	this->sedentarism = sedentarism;
}

Adultpeste40::Adultpeste40(const Adultpeste40 & A): Pacient(A){
	this->fumator = A.fumator;
	this->sedentarism = A.sedentarism;
}

Adultpeste40& Adultpeste40::operator=(const Adultpeste40& A){
	if(&A == this) return *this;
	Pacient::operator=(A);
	this->fumator = A.fumator;
	this->sedentarism = A.sedentarism;
	return *this;
}
Adultpeste40::~Adultpeste40(){

}


void Adultpeste40::citire(){
	std::cin >> nume;
	std::cin >> prenume;
	std::cin >> varsta;
	std::cin >> colesterol;
	std::cin >> tensiuneArteriala;
	std::cin >> datacolesterol;
	std::cin >> datatensiune;
	std::cin >> fumator;
	std::cin >> sedentarism;
}

void Adultpeste40::afisare(){
	std::cout << this->nume << " " << this->prenume << ": Risc cardiovascular: " << this->gradRiscCardiovascular() << "; Colesterol: (" << this->datacolesterol << "): ";
	std::cout << this->colesterol << "mg/dl; TA: (" << this->datatensiune << "): " << this->tensiuneArteriala << ".\n"; 
	std::cout << "Fumator: " << this->fumator << "; sedentarism: " << this->sedentarism << "\n";
}

std::string Adultpeste40::gradRiscCardiovascular(){
	int simptome = 0;
	if(this->colesterol > 240 or this->tensiuneArteriala > 139) simptome++;

	if(this->fumator == "da" and this->sedentarism == "ridicat") simptome++;

	if(simptome == 2) return "RIDICAT";
	if(simptome == 1) return "DA";
	return "NU";
}

std::string Adultpeste40::getType(){
	return "Adultpeste40";
}