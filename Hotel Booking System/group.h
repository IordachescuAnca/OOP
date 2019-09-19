#pragma once
#include "person.h"
#include <vector>
#include <unistd.h>


class Group
{
private:
	std::vector<Person> people;
	int period;
	int typeConferenceRoom;
public:
	Group(int = 0, int = 0);
	Group(const Group&);
	Group& operator=(const Group&);
	~Group();

	int getNumberPeople();
	int getNumberPeopleBreakfast();
	int getConferenceRoom();
	int getPeriod();

	friend std::istream& operator>>(std::istream&, Group&);
	friend std::ostream& operator<<(std::ostream&, const Group&);
	friend class Hotel;
};



Group::Group(int period_p, int typeConferenceRoom_p)
{
	this->period = period_p;
	this->typeConferenceRoom = typeConferenceRoom_p;
}

Group::Group(const Group& G)
{
	this->people = G.people;
	this->period = G.period;
	this->typeConferenceRoom = G.typeConferenceRoom;
}

Group& Group::operator=(const Group& G)
{
	if(this != &G)
	{
		this->people = G.people;
		this->period = G.period;
		this->typeConferenceRoom = G.typeConferenceRoom;
	}

	return *this;
}

Group::~Group()
{
	this->people.clear();
	this->period = 0;
	this->typeConferenceRoom = 0;
}

std::istream& operator>>(std::istream& input, Group& G)
{
	std::cout << "\nEnter the booking period of the group.\n";
	sleep(1);
	input >> G.period;
	std::cout << "\nEnter 1 if the group wants to book a conference room or 0 otherwise.\n";
	sleep(1);
	int choice1;
	input >> choice1;
	if(choice1 != 1 && choice1 != 0)
	{
		std::cout << "\nSorry, this option doesn't exist. By default this group will not book a conference room.\n";
		sleep(1);
		G.typeConferenceRoom = 0;
	}
	else
	{
		if(!choice1)
		{
			G.typeConferenceRoom = 0;
		}
		else
		{
			std::cout << "\nEnter 1 if the group wants the conference room to be stage or \n0 if the group wants the conference room to be individual.\n";
			sleep(1);
			int choice2;
			input >> choice2;
			if(choice2 != 1 && choice2 != 0)
			{
				std::cout << "\nSorry, this option doesn't exist. By default this group will not book a conference room.\n";
				sleep(1);
				G.typeConferenceRoom = 0;
			}
			else
			{
				G.typeConferenceRoom = choice2;
			}
		}
	}

	std::cout << "\nEnter the number of people of the group.\n";
	sleep(1);
	int number;
	input >> number;
	if(number < 0)
	{
		std::cout << "\nSorry, it is impossible not to have a group with at least one person. By default, the number of people of the group is 0.\n";
		return input;
	}

	std::cout << "\nEnter the people of the group.\n";
	sleep(1);
	for(int i = 0; i < number; ++i)
	{
		std::cout << "Person number " << i+1 << ":\n";
		Person P;
		input >> P;
		G.people.push_back(P);
	}
	return input;
}

std::ostream& operator<<(std::ostream& output, const Group& G)
{
	output << "\nDetails about the group.\n";
	output << "\nThe booking period of the group is of " << G.period << " days.";
	
	switch(G.typeConferenceRoom)
	{
		case 0:
		output << "\nThe group doesn't want a conference room.";
		break;
		case 1:
		output << "\nThe group wants a conference room(stage).";
		break;
		case 2:
		output << "\nThe group wants a conference room(individual).";
		break;
	}

	output << "\nThe number of people of the group is " << G.people.size() << ".\n";
	output << "\nThe people of the group are:\n";
	for(unsigned int i = 0; i < G.people.size(); ++i)
	{
		output << "Person number " << i+1 << ":\n";
		output << G.people[i] << "\n";
	}

	return output;
}

int Group::getNumberPeople()
{
	return people.size();
}
int Group::getNumberPeopleBreakfast()
{
	int cnt = 0;
	for(unsigned int i = 0; i < people.size(); i++)
	{
		cnt += people[i].getBreakfast();
	}
	return cnt;
}

int Group::getConferenceRoom()
{
	return typeConferenceRoom;
}

int Group::getPeriod()
{
	return period;
}