#pragma once
#include<vector>

class Room
{
public:
	static int numberRooms;
	std::vector<bool>busyRoom = std::vector<bool>(367,0);
public:
	Room();
	Room(const Room&);
	Room& operator=(const Room&);
	virtual ~Room();

	virtual std::string type() const = 0;
	virtual void readData(std::istream&) = 0;
	virtual void writeData(std::ostream&) = 0;
	virtual int getCapacity() = 0;

	void setBusyRoom(int, bool);
	bool getBusyRoom(int);

};
int Room::numberRooms = 0;

Room::Room()
{
	this->numberRooms++;
}

Room::Room(const Room& R)
{
	this->numberRooms++;
	for(int i = 1; i <= 365; i++)
	{
		busyRoom[i] = R.busyRoom[i];
	}
}

Room& Room::operator=(const Room& R)
{
	if(this != &R)
	{
		this->numberRooms = R.numberRooms;
		for(int i = 1; i <= 365; i++)
		{
			busyRoom[i] = R.busyRoom[i];
		}
	}
	return *this;
}

Room::~Room()
{
	this->numberRooms--;
	this->busyRoom.clear();
}

void Room::setBusyRoom(int day, bool status)
{
	if(day > 0 && day < 366)
	{
		busyRoom[day] = status;
	}
}

bool Room::getBusyRoom(int day)
{
	return busyRoom[day];
}