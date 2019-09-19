#pragma once
#include "room.h"

class TwinRoom: public Room
{
private:
	const static int numberBeds = 2;
	int price;
public:
	TwinRoom(int = 0);
	TwinRoom(const TwinRoom&);
	TwinRoom& operator=(const TwinRoom&);
	~TwinRoom();

	int getCapacity();

	virtual std::string type() const;
	virtual void readData(std::istream&);
	virtual void writeData(std::ostream&);
};

TwinRoom::TwinRoom(int price_p) : Room(), price(price_p) {}

TwinRoom::TwinRoom(const TwinRoom& TR) : Room(TR), price(TR.price) {}

TwinRoom& TwinRoom::operator=(const TwinRoom& TR)
{
	this->Room::operator=(TR);
	this->price = TR.price;
	return *this;
}

TwinRoom::~TwinRoom()
{
	this->price = 0;
}

std::string TwinRoom::type() const
{
	return "TwinRoom";
}

void TwinRoom::readData(std::istream& input)
{
	std::cout << "\nEnter the price of a twin room.\n";
	input >> price;
}

void TwinRoom::writeData(std::ostream& output)
{
	output << "\nThe price of a twin room is " << price << ".\n";
}

int TwinRoom::getCapacity()
{
	return numberBeds;
}
