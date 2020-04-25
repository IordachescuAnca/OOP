#include "pacient.h"

int Pacient::contor = 0;

Pacient::Pacient(std::string nume, std::string prenume, int varsta, double colesterol, double tensiuneArteriala, std::string datacolesterol, std::string datatensiune){
	this->nume = nume;
	this->prenume = prenume;
	this->varsta = varsta;
	this->colesterol = colesterol;
	this->tensiuneArteriala = tensiuneArteriala;
	this->datacolesterol = datacolesterol;
	this->datatensiune = datatensiune;
	contor++;
	this->id = contor;
}

Pacient::Pacient(const Pacient &P){
	this->nume = P.nume;
	this->prenume = P.prenume;
	this->varsta = P.varsta;
	this->colesterol = P.colesterol;
	this->tensiuneArteriala = P.tensiuneArteriala;
	this->datacolesterol = P.datacolesterol;
	this->datatensiune = P.datatensiune;
}


Pacient& Pacient::operator=(const Pacient &P){
	if (this == &P) return *this;
	this->nume = nume;
	this->prenume = prenume;
	this->varsta = varsta;
	this->colesterol = colesterol;
	this->tensiuneArteriala = tensiuneArteriala;
	this->datacolesterol = P.datacolesterol;
	this->datatensiune = P.datatensiune;
	return *this;
}

Pacient::~Pacient(){
	this->nume.clear();
	this->prenume.clear();
	this->datacolesterol.clear();
	this->datatensiune.clear();
}

int Pacient::getId() const{
	return this->id;
}

std::string Pacient::getNume() const{
	return this->nume;
}