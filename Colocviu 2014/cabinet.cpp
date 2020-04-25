#include "cabinet.h"
#include "pacient.h"
#include "copil.h"
#include "adultsub40.h"
#include "adultpeste40.h"
#include<iostream>
#include <typeinfo>

Cabinet* Cabinet::instance = nullptr;

Cabinet::Cabinet(std::string numeDoctor, std::string adresa): numeDoctor(numeDoctor), adresa(adresa){}

Cabinet* Cabinet::getInstance(std::string numeDoctor, std::string adresa){
	if(instance == nullptr){
		instance = new Cabinet(numeDoctor, adresa);
	}
	return instance;
}


std::string Cabinet::getNumeDoctor(){
	return this->numeDoctor;
}
void Cabinet::setNumeDoctor(std::string numeDoctor){
	this->numeDoctor = numeDoctor;
}
std::string Cabinet::getAdresa(){
	return this->adresa;
}
void Cabinet::setAdresa(std::string adresa){
	this->adresa = adresa;
}

void Cabinet::mesaj(){
	std::cout << "Adresa: " << this->adresa << "\n";
	std::cout << "Doctor: " << this->numeDoctor << "\n";
	std::cout << "Meniu:\n";
	std::cout << "1.Afiseaza toti pacientii.\n";
	std::cout << "2.Afiseaza pacientii adulti cu factor de risc cardiovascular ridicat.\n";
	std::cout << "3.Afiseaza pacientii copii cu factor de risc cardiovascular.\n";
	std::cout << "4.Afiseaza pacientii al caror nume de familie este cel dat de la tastatura.\n";
	std::cout << "5.Adauga pacient\n";
	std::cout << "6.Iesire\n";
}

void Cabinet::afiseazaCopiiRisc(){
	std::cout << "Copii:\n";
	for(unsigned int i = 0; i < pacienti.size(); i++){
		if(pacienti[i]->getType() == "Copil" and (pacienti[i]->gradRiscCardiovascular() == "RIDICAT" or pacienti[i]->gradRiscCardiovascular() == "DA")){
			this->afiseazaPacient(i);
		}
	}
}

void Cabinet::afiseazaPacientiNume(std::string nume){
	for(unsigned int i = 0; i < pacienti.size(); i++){
		if(pacienti[i]->getType() == "Adultsub40" and pacienti[i]->getNume() == nume){
			this->afiseazaPacient(i);
		}
	}
	std::cout << "Adulti peste 40 ani:\n";
	for(unsigned int i = 0; i < pacienti.size(); i++){
		if(pacienti[i]->getType() == "Adultpeste40" and pacienti[i]->getNume() == nume){
			this->afiseazaPacient(i);
		}
	}
	std::cout << "Copii:\n";
	for(unsigned int i = 0; i < pacienti.size(); i++){
		if(pacienti[i]->getType() == "Copil" and pacienti[i]->getNume() == nume){
			this->afiseazaPacient(i);
		}
	}
}

void Cabinet::afiseazaAdultiRiscRidicat(){
	std::cout << "Adulti peste 40 ani:\n";
	for(unsigned int i = 0; i < pacienti.size(); i++){
		if(pacienti[i]->getType() == "Adultpeste40" and pacienti[i]->gradRiscCardiovascular() == "RIDICAT"){
			this->afiseazaPacient(i);
		}
	}
}

void Cabinet::adaugaPacient(std::string tip){
	Pacient *p;
	if(tip == "adultsub40"){
		p = new Adultsub40();
	}
	if(tip == "adultpeste40"){
		p = new Adultpeste40();
	}
	if(tip == "copil"){
		p = new Copil();
	}
	p->citire();
	pacienti.push_back(p);
}

void Cabinet::afiseazaPacient(int i){
	std::cout << "Id: " << pacienti[i]->getId() << "\n";
	pacienti[i]->afisare();
	std::cout << "\n";
}

void Cabinet::afiseazaPacienti(){
	std::cout << "Adulti sub 40 ani:\n";
	for(unsigned int i = 0; i < pacienti.size(); i++){
		if(pacienti[i]->getType() == "Adultsub40"){
			this->afiseazaPacient(i);
		}
	}
	std::cout << "Adulti peste 40 ani:\n";
	for(unsigned int i = 0; i < pacienti.size(); i++){
		if(pacienti[i]->getType() == "Adultpeste40"){
			this->afiseazaPacient(i);
		}
	}
	std::cout << "Copii:\n";
	for(unsigned int i = 0; i < pacienti.size(); i++){
		if(pacienti[i]->getType() == "Copil"){
			this->afiseazaPacient(i);
		}
	}
}