#pragma once
#include "room.h"

class Restaurant: public Room
{
private:
	int priceBreakfast;
	int capacity;
public:
	Restaurant(int = 0, int = 0);
	Restaurant(const Restaurant&);
	Restaurant& operator=(const Restaurant&);
	~Restaurant();

	int getCapacity();

	virtual std::string type() const;
	virtual void readData(std::istream&);
	virtual void writeData(std::ostream&);
};

Restaurant::Restaurant(int priceBreakfast_p, int capacity_p): Room()
{
	this->priceBreakfast = priceBreakfast_p;
	this->capacity = capacity_p;
}

Restaurant::Restaurant(const Restaurant& R) : Room(R)
{
	this->priceBreakfast = R.priceBreakfast;
	this->capacity = R.capacity;
}

Restaurant& Restaurant::operator=(const Restaurant &R)
{
	if(this != &R)
	{
		this->Room::operator=(R);
		this->priceBreakfast = R.priceBreakfast;
		this->capacity = R.capacity;	
	}
	return *this;
}

Restaurant::~Restaurant()
{
	this->priceBreakfast = 0;
	this->capacity = 0;
}

std::string Restaurant::type() const
{
	return "Restaurant";
}

void Restaurant::readData(std::istream& input)
{
	std::cout << "\nEnter the capacity of the restaurant.\n";
	input >> capacity;
	std::cout << "\nEnter the price for breakfast.\n";
	input >> priceBreakfast;
}

void Restaurant::writeData(std::ostream& output)
{
	output << "\nThe capacity of the restaurant is " << capacity << ".\n";
	output << "\nThe price of the breakfast is " << priceBreakfast << ".\n";
}

int Restaurant::getCapacity()
{
	return capacity;
}