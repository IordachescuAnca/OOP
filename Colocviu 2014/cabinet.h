#pragma once
#include<string>
#include<vector>
#include "pacient.h"

class Cabinet{ //SINGLETON
private:
	std::string numeDoctor;
	std::string adresa;
	static Cabinet* instance;
	Cabinet(std::string = "", std::string = "");
	std::vector<Pacient*> pacienti;

public:
	static Cabinet* getInstance(std::string, std::string);
	std::string getNumeDoctor();
	void setNumeDoctor(std::string);
	std::string getAdresa();
	void setAdresa(std::string);
	void mesaj();
	void adaugaPacient(std::string);
	void afiseazaPacienti();
	void afiseazaPacient(int);
	void afiseazaPacientiNume(std::string);
	void afiseazaAdultiRiscRidicat();
	void afiseazaCopiiRisc();
};