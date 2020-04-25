#include<iostream>
#include "cabinet.h"

int main(){

	Cabinet *C = C->getInstance("Strada X NR. Y", "Popescu Ion");
	while(true){
		C->mesaj();
		int alegere;
		std::cin >> alegere;

		if(alegere == 1){
			C->afiseazaPacienti();
		}
		if(alegere == 2){
			C->afiseazaAdultiRiscRidicat();
		}
		if(alegere == 3){
			C->afiseazaCopiiRisc();
		}
		if(alegere == 4){
			std::cout << "Introduce nume:\n";
			std::string nume;
			std::cin >> nume;
			C->afiseazaPacientiNume(nume);
		}
		if(alegere == 5){
			std::cout << "Clientul este adult sub 40 de ani, adult peste 40 de ani sau copil?\n";
			std::string tipPacient;
			std::cin >> tipPacient;
			C->adaugaPacient(tipPacient);
		}
		if(alegere == 6){
			std::cout << "Ai ales sa iesi din meniu.";
			break;
		}
		if(alegere < 1 or alegere > 6){
			std::cout << "Tasta incorecta.";
		}
		std::cout << "\n";
	}
}