#include "adultsub40.h"
#include <iostream>

Adultsub40::Adultsub40(std::string nume, std::string prenume, int varsta, double colesterol, double tensiuneArteriala, std::string datacolesterol, std::string datatensiune): Pacient(nume, prenume, varsta, colesterol, tensiuneArteriala, datacolesterol, datatensiune){}

Adultsub40::Adultsub40(const Adultsub40 & A): Pacient(A){}

Adultsub40& Adultsub40::operator=(const Adultsub40& A){
	if(&A == this) return *this;
	Pacient::operator=(A);
	return *this;
}
Adultsub40::~Adultsub40(){

}


void Adultsub40::citire(){
	std::cin >> nume;
	std::cin >> prenume;
	std::cin >> varsta;
	std::cin >> colesterol;
	std::cin >> tensiuneArteriala;
	std::cin >> datacolesterol;
	std::cin >> datatensiune;
}

void Adultsub40::afisare(){
	std::cout << this->nume << " " << this->prenume << ": Risc cardiovascular: " << this->gradRiscCardiovascular() << "; Colesterol: (" << this->datacolesterol << "): ";
	std::cout << this->colesterol << "mg/dl; TA: (" << this->datatensiune << "): " << this->tensiuneArteriala << ".\n"; 
}

std::string Adultsub40::gradRiscCardiovascular(){
	int simptome = 0;
	if(this->colesterol > 240) simptome++;
	if(this->tensiuneArteriala > 139) simptome++;

	if(simptome >= 1) return "DA";
	return "NU";
}

std::string Adultsub40::getType(){
	return "Adultsub40";
}