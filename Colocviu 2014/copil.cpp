#include "copil.h"
#include <iostream>

Copil::Copil(std::string nume, std::string prenume, int varsta, double colesterol, double tensiuneArteriala, std::string datacolesterol, std::string datatensiune, std::string antecedentefamilie, std::string numeMama, std::string numeTata, std::string dataProteinaC, double proteinaC): Pacient(nume, prenume, varsta, colesterol, tensiuneArteriala, datacolesterol, datatensiune){
	this->antecedentefamilie = antecedentefamilie;
	this->numeMama = numeMama;
	this->numeTata = numeTata;
	this->dataProteinaC = dataProteinaC;
	this->proteinaC = proteinaC;
}

Copil::Copil(const Copil& A): Pacient(A){
	this->antecedentefamilie = A.antecedentefamilie;
	this->numeMama = A.numeMama;
	this->numeTata = A.numeTata;
	this->dataProteinaC = A.dataProteinaC;
	this->proteinaC = A.proteinaC;
}

Copil& Copil::operator=(const Copil& A){
	if(&A == this) return *this;
	Pacient::operator=(A);
	this->antecedentefamilie = A.antecedentefamilie;
	this->numeMama = A.numeMama;
	this->numeTata = A.numeTata;
	this->dataProteinaC = A.dataProteinaC;
	this->proteinaC = A.proteinaC;
	return *this;
}
Copil::~Copil(){

}


void Copil::citire(){
	std::cin >> nume;
	std::cin >> prenume;
	std::cin >> varsta;
	std::cin >> colesterol;
	std::cin >> tensiuneArteriala;
	std::cin >> datacolesterol;
	std::cin >> datatensiune;
	std::cin >> antecedentefamilie;
	std::cin >> numeMama;
	std::cin >> numeTata;
	std::cin >> dataProteinaC;
	std::cin >> proteinaC;
}

void Copil::afisare(){
	std::cout << this->nume << " " << this->prenume << ": Risc cardiovascular: " << this->gradRiscCardiovascular() << "; Colesterol: (" << this->datacolesterol << "): ";
	std::cout << this->colesterol << "mg/dl; TA: (" << this->datatensiune << "): " << this->tensiuneArteriala << ".\n"; 
	std::cout << "Proteina C reactiva: " << this->proteinaC << " mg/dl; Antecedente familie: " << this->antecedentefamilie;
}

std::string Copil::gradRiscCardiovascular(){
	int simptome = 0;
	if(this->colesterol > 240 or this->tensiuneArteriala > 139) simptome++;
	if(this->antecedentefamilie == "da") simptome++;

	if(simptome == 2) return "RIDICAT";
	if(simptome == 1) return "DA";
	return "NU";
}

std::string Copil::getType(){
	return "Copil";
}