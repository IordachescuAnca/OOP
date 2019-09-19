#pragma once
#include "twin_room.h"
#include "quadruble_room.h"
#include "stage_room.h"
#include "individual_c_room.h"
#include "restaurant.h"
#include "group.h"
#include "room.h"
#include <vector>
#include <memory>

class Hotel
{
private:
	std::vector<Room*> rooms;
	int numberRooms;
	std::string name;
	std::string city;

	bool checkDay(int, Group);
	bool checkPeriod(Group);
	int getFirstDayReservation(Group);
	void bookDay(int, Group);

public:
	Hotel(std::string = "", std::string city = "");
	Hotel(const Hotel&);
	Hotel& operator=(const Hotel&);
	~Hotel();

	void request_reservation(Group);
	void introduction();

	void readData(std::istream&);
	void writeData(std::ostream&);

	friend class Group;

};

Hotel::Hotel(std::string name_p, std::string city_p): name(name_p), city(city_p) {}

Hotel::Hotel(const Hotel& H)
{
	for(int i = 1; i <= 365; ++i)
	{
		this->rooms[i] = H.rooms[i];
	}
	this->name = H.name;
	this->city = H.city;
}

Hotel& Hotel::operator=(const Hotel &H)
{
	if(this != &H)
	{
		for(int i = 1; i <= 365; ++i)
		{
			this->rooms[i] = H.rooms[i];
		}
		this->name = H.name;
		this->city = H.city;
	}
	return *this;
}

Hotel::~Hotel()
{
	this->name = "";
	this->city = "";
	rooms.clear();
}

void Hotel::readData(std::istream& input)
{
	std::cout << "\nEnter the name of the hotel.\n";
	input >> name;
	std::cout << "\nEnter the city where the hotel is situated in.\n";
	input >> city;

	std::cout << "\nEnter the number of rooms of the hotel.\n";
	input >> numberRooms;

	int no;
	int cnt = 0;

	std::cout << "\nEnter the number of twin rooms.\n";
	input >> no;

	for(int i = 0; i < no; ++i)
	{
		cnt++;
		std::cout << "\nRoom number " << cnt << ".\n";
		std::cout << "Enter the details of the twin room.\n";

		Room *TR = new TwinRoom();
		TR->readData(input);
		rooms.push_back(TR);
	}

	std::cout << "\nEnter the number of quadruble rooms.\n";
	input >> no;

	for(int i = 0; i < no; ++i)
	{
		cnt++;
		std::cout << "\nRoom number " << cnt << ".\n";
		std::cout << "Enter the details of the quadruble room.\n";

		Room *QR = new QuadrubleRoom();
		QR->readData(input);
		rooms.push_back(QR);
	}

	std::cout << "\nEnter the number of stage conference rooms.\n";
	input >> no;

	for(int i = 0; i < no; ++i)
	{
		cnt++;
		std::cout << "\nRoom number " << cnt << ".\n";
		std::cout << "Enter the details of the stage conference room.\n";

		Room *SCR = new StageConferenceRoom();
		SCR->readData(input);
		rooms.push_back(SCR);
	}

	std::cout << "\nEnter the number of individual conference rooms.\n";
	input >> no;

	for(int i = 0; i < no; ++i)
	{
		cnt++;
		std::cout << "\nRoom number " << cnt << ".\n";
		std::cout << "Enter the details of the individual conference room.\n";

		Room *ICR = new IndividualConferenceRoom();
		ICR->readData(input);
		rooms.push_back(ICR);
	}

	cnt++;
	std::cout << "\nRoom number " << cnt << ".\n";

	std::cout << "\nEnter the details of the restaurant.\n";
	Room *R = new Restaurant();
	R->readData(input);
	rooms.push_back(R);

}

void Hotel::writeData(std::ostream& output)
{
	output << "\nThe name of the hotel is " << name << ".\n";
	output << "\nThe city where the hotel is situated in is " << city << ".\n";
	output << "\nThe rooms of the hotel are:\n";

	for(int i = 0; i < numberRooms; ++i)
	{
		output << "\nRoom." << i+1 << "\n";
		rooms[i]->writeData(output);
	}	
}

bool Hotel::checkDay(int day, Group G)
{
	int capacity = 0;
	for(unsigned int i = 0; i < rooms.size(); ++i)
	{
		if((rooms[i]->type() == "TwinRoom") || (rooms[i]->type() == "QuadrubleRoom"))
		{
			capacity += rooms[i]->getCapacity();
		}
	}
	if(capacity < G.getNumberPeople())
	{
		return false;
	}

	if(rooms[rooms.size()-1]->getCapacity() < G.getNumberPeopleBreakfast())
	{
		return false;
	}

	if(G.getConferenceRoom() == 1)
	{
		bool check = 0;
		for(unsigned int i = 0; i < rooms.size(); ++i)
		{
			if(rooms[i]->type() == "StageConferenceRoom")
			{
				check = 1;
				break;
			}
		}
		if(!check)
		{
			return false;
		}
	}

	if(G.getConferenceRoom() == 2)
	{
		bool check = 0;
		for(unsigned int i = 0; i < rooms.size(); ++i)
		{
			if(rooms[i]->type() == "IndividualConferenceRoom")
			{
				check = 1;
				break;
			}
		}
		if(!check)
		{
			return false;
		}
	}

	return true;
}

bool Hotel::checkPeriod(Group G)
{

	for(int i = 1; i <= 366-G.getPeriod(); ++i)
	{
		bool check = 1;
		for(int j = 0; j <= G.getPeriod()-1; ++j)
		{
			if(checkDay(i+j,G) == 0)
			{
				check = 0;
				break;
			}
		}
		if(check == 1)
		{
			return true;
		}
	}
	return false;
}

int Hotel::getFirstDayReservation(Group G)
{
	for(int i = 1; i <= 366-G.getPeriod(); ++i)
	{
		bool check = 1;
		for(int j = 0; j <= G.getPeriod()-1; ++j)
		{
			if(checkDay(i+j,G) == 0)
			{
				check = 0;
				break;
			}
		}
		if(check == 1)
		{
			return i;
		}
	}
	return -1;
}

void Hotel::request_reservation(Group G)
{
	if(checkPeriod(G))
	{
		int firstDay = getFirstDayReservation(G);
		std::cout << "The check in date is " << firstDay <<". The check out day is " << firstDay+G.getPeriod() << ".\n";
		for(int i = 0; i < G.getPeriod(); ++i)
		{
			bookDay(firstDay+i, G);
		}
	}
	else
	{
		std::cout << "Sorry, this reservation can't be executed.\n";
	}
}

void Hotel::bookDay(int day, Group G)
{
	int numberppl = G.getNumberPeople();
	for(unsigned int i = 0; i < rooms.size(); ++i)
	{
		if(rooms[i]->type() == "TwinRoom")
		{
			if(rooms[i]->getBusyRoom(day) == 0)
			{
				rooms[i]->setBusyRoom(day, 1);
				numberppl -=2;
			}
		}
		if(rooms[i]->type() == "QuadrubleRoom")
		{
			if(rooms[i]->getBusyRoom(day) == 0)
			{
				rooms[i]->setBusyRoom(day, 1);
				numberppl -=4;
			}
		}
		if(numberppl <= 0)
		{
			break;
		}
	}
	if(G.getConferenceRoom())
	{
		if(G.getConferenceRoom() == 1)
		{
			for(unsigned int i = 0; i < rooms.size(); ++i)
			{
				if(rooms[i]->type() == "StageConferenceRoom" && rooms[i]->getBusyRoom(day) == 0)
				{
					rooms[i]->setBusyRoom(day, 1);
					break;
				}
			}
		}
		if(G.getConferenceRoom() == 1)
		{
			for(unsigned int i = 0; i < rooms.size(); ++i)
			{
				if(rooms[i]->type() == "IndividualConferenceRoom" && rooms[i]->getBusyRoom(day) == 0)
				{
					rooms[i]->setBusyRoom(day, 1);
					break;
				}
			}
		}
	}

}

void Hotel::introduction()
{
	std::cout << "Hello!\nEnter the option you want.\n";
	std::cout << "1.Request a reservation.\n";
	std::cout << "2.The details about the hotel.\n";
	std::cout << "3.Exit.\n";
}