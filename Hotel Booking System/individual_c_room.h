#pragma once 
#include "stage_room.h"
#include <stdexcept>
#include <vector>

class IndividualConferenceRoom: public StageConferenceRoom
{
private:
	std::vector<int> tables;
public:
	IndividualConferenceRoom(bool = 0, int = 0, int = 0);
	IndividualConferenceRoom(const IndividualConferenceRoom&);
	IndividualConferenceRoom& operator=(const IndividualConferenceRoom&);
	~IndividualConferenceRoom();

	virtual std::string type() const;
	virtual void readData(std::istream&);
	virtual void writeData(std::ostream&);
};

IndividualConferenceRoom::IndividualConferenceRoom(bool hasVideoProjector_p, int capacity_p, int price_p): StageConferenceRoom(hasVideoProjector_p, capacity_p, price_p) {}

IndividualConferenceRoom::IndividualConferenceRoom(const IndividualConferenceRoom& ICR) : StageConferenceRoom(ICR)
{
	this->tables = ICR.tables;
}

IndividualConferenceRoom& IndividualConferenceRoom::operator=(const IndividualConferenceRoom& ICR)
{
	if(this != &ICR)
	{
		this->StageConferenceRoom::operator=(ICR);
		this->tables.clear();
		this->tables = ICR.tables;
	}
	return *this;
}

IndividualConferenceRoom::~IndividualConferenceRoom()
{
	this->tables.clear();
}

std::string IndividualConferenceRoom::type() const
{
	return "IndividualConferenceRoom";
}

void IndividualConferenceRoom::readData(std::istream& input)
{
	this->StageConferenceRoom::readData(input);

	std::cout << "\nEnter the number of tables\n";
	int number;
	input >> number;

	std::cout << "\nEnter the capacity of each table.\n";
	this->tables.clear();
	for(int i = 0; i < number; ++i)
	{
		int x;
		input >> x;
		if(x < 4 || x > 8)
		{
			throw std::invalid_argument("Error!");
		}
		tables.push_back(x);
	}
}

void IndividualConferenceRoom::writeData(std::ostream& output)
{
	this->StageConferenceRoom::writeData(output);

	output << "\nThe number of tables is " << tables.size() << ".\n";
	output << "\nThe capacity of each tables:\n";
	for(unsigned int i = 0; i < tables.size(); ++i)
	{
		output << "Table " << i+1 << ": " << tables[i] << ".\n";
	}
}