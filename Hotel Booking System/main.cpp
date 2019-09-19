#include<iostream>
#include "hotel.h"
#include "group.h"


int main()
{
	Hotel H;
	H.readData(std::cin);

	Group G;
	while(1)
	{
		int exit = 0;
		H.introduction();

		int choice;
		std::cin >> choice;
		switch(choice)
		{
			case 1:
			std::cin >> G;
			H.request_reservation(G);
			break;

			case 2:
			H.writeData(std::cout);
			break;

			case 3:
			exit = 1;

			default:
			break;
		}
		if(exit == 1)
		{
			break;
		}
	}

	return 0;
}