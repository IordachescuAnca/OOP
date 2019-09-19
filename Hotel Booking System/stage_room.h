#pragma once
#include "room.h"

class StageConferenceRoom: public Room
{
protected:
	bool hasVideoProjector;
	int capacity;
	int price;
public:
	StageConferenceRoom(bool = 0, int = 0, int = 0);
	StageConferenceRoom(const StageConferenceRoom&);
	StageConferenceRoom& operator=(const StageConferenceRoom&);
	virtual ~StageConferenceRoom();

	int getCapacity();

	virtual std::string type() const;
	virtual void readData(std::istream&);
	virtual void writeData(std::ostream&);
};

StageConferenceRoom::StageConferenceRoom(bool hasVideoProjector_p, int capacity_p, int price_p): Room(), price(price_p)
{
	this->hasVideoProjector = hasVideoProjector_p;
	this->capacity = capacity_p;
}

StageConferenceRoom::StageConferenceRoom(const StageConferenceRoom& SCR) : Room(SCR)
{
	this->hasVideoProjector = SCR.hasVideoProjector;
	this->capacity = SCR.capacity;
	this->price = SCR.price;
}

StageConferenceRoom& StageConferenceRoom::operator=(const StageConferenceRoom& SCR)
{
	this->Room::operator=(SCR);
	this->price = SCR.price;
	this->hasVideoProjector = SCR.hasVideoProjector;
	this->capacity = SCR.capacity;
	return *this;
}

StageConferenceRoom::~StageConferenceRoom()
{
	this->price = 0;
	this->hasVideoProjector = 0;
	this->capacity = 0;
}

std::string StageConferenceRoom::type() const
{
	return "StageConferenceRoom";
}

void StageConferenceRoom::readData(std::istream& input)
{
	std::cout << "\nEnter the capacity of the conference room.\n";
	input >> capacity;

	std::cout << "\nEnter the price of a conference room.\n";
	input >> price;

	std::cout << "\nEnter 1 if the conference room has a video projector or 0 otherwise.\n";
	int choice;
	input >> choice;
	if(choice != 0 && choice != 1)
	{
		std:: cout << "\nSorry, this option doesn't exist. By default, the conference room will not have a video projector.\n";
		this->hasVideoProjector = 0;
	}
	else
	{
		this->hasVideoProjector = choice;
	}
}

void StageConferenceRoom::writeData(std::ostream& output)
{
	output << "\nThe capacity of the conference room is " << capacity << ".\n";
	output << "\nThe price of the conference room is " << price << ".\n";
	if(hasVideoProjector == 0)
	{
		output << "\nThe conference room doesn't have any video projector.\n";
	}
	else
	{
		output << "\nThe conference room has a video projector.\n";
	}
}

int StageConferenceRoom::getCapacity()
{
	return capacity;
}