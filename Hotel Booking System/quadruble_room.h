#pragma once
#include "room.h"

class QuadrubleRoom: public Room
{
private:
	const static int numberBeds = 4;
	int price;
public:
	QuadrubleRoom(int = 0);
	QuadrubleRoom(const QuadrubleRoom&);
	QuadrubleRoom& operator=(const QuadrubleRoom&);
	~QuadrubleRoom();

	int getCapacity();

	virtual std::string type() const;
	virtual void readData(std::istream&);
	virtual void writeData(std::ostream&);
};

QuadrubleRoom::QuadrubleRoom(int price_p) : Room(), price(price_p) {}

QuadrubleRoom::QuadrubleRoom(const QuadrubleRoom& QR) : Room(QR), price(QR.price) {}

QuadrubleRoom& QuadrubleRoom::operator=(const QuadrubleRoom& QR)
{
	this->Room::operator=(QR);
	this->price = QR.price;
	return *this;
}

QuadrubleRoom::~QuadrubleRoom()
{
	this->price = 0;
}

std::string QuadrubleRoom::type() const
{
	return "QuadrubleRoom";
}

void QuadrubleRoom::readData(std::istream& input)
{
	std::cout << "\nEnter the price of a quadruble room.\n";
	input >> price;
}

void QuadrubleRoom::writeData(std::ostream& output)
{
	output << "\nThe price of a quadruble room is " << price << ".\n";
}

int QuadrubleRoom::getCapacity()
{
	return numberBeds;
}