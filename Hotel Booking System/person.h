#pragma once
#include <unistd.h>

class Person
{
private:
	std::string firstName;
	std::string lastName;
	int age;
	bool hasBreakfast;
public:
	Person(std::string = "", std::string = "", int = -1, bool = 0);
	Person(const Person&);
	Person& operator=(const Person&);
	~Person();

	bool getBreakfast();

	friend std::istream& operator>>(std::istream&, Person&);
	friend std::ostream& operator<<(std::ostream&, const Person&);
};

Person::Person(std::string firstName_p,std::string lastName_p,int age_p,bool hasBreakfast_p)
{
	this->firstName = firstName_p;
	this->lastName = lastName_p;
	this->age = age_p;
	this->hasBreakfast = hasBreakfast_p;
}

Person::Person(const Person &P)
{
	this->firstName = P.firstName;
	this->lastName = P.lastName;
	this->age = P.age;
	this->hasBreakfast = P.hasBreakfast;
}

Person& Person::operator=(const Person &P)
{
	if(this != &P)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->age = age;
		this->hasBreakfast = hasBreakfast;
	}
	return *this;
}

Person::~Person()
{
	this->firstName = "";
	this->lastName = "";
	this->age = -1;
	this->hasBreakfast = 0;
}

std::istream& operator>>(std::istream& input, Person& P)
{
	std::cout << "\nEnter the first name.\n";
	sleep(1);
	input >> P.firstName;
	std::cout << "\nEnter the last name.\n";
	sleep(1);
	input >> P.lastName;
	std::cout << "\nEnter the age.\n";
	sleep(1);
	input >> P.age;
	if(P.age < 0)
	{
		std::cout << "\nSorry, a person has to be at least one year old. By default, this person is 0 year old.\n";
		sleep(1);
	}
	std::cout << "\nEnter 1 if the person wants to have breakfast at restaurant or 0 if the person wants to have breakfast in the hotel room.\n";
	sleep(1);
	int choice;
	input >> choice;
	if(choice != 0 && choice != 1)
	{
		std::cout << "\nSorry, this option doesn't exist. By default " << P.firstName << " " << P.lastName << " will have breakfast in the hotel room.\n";
		sleep(1);
	}
	else
	{
		P.hasBreakfast = choice;
	}
	return input;
}

std::ostream& operator<<(std::ostream& output,const Person& P)
{
	output << "\nDetails about the person.\n";
	output << "\nThe person called " << P.firstName << " " << P.lastName << " is " << P.age << " years old ";
	if(P.hasBreakfast)
	{
		output << "and wants to have breakfast at restaurant during the trip.\n";
	} 
	else
	{
		output << "and wants to have breakfast in the hotel room during the trip.\n";
	}
	return output;
}

bool Person::getBreakfast()
{
	return hasBreakfast;
}