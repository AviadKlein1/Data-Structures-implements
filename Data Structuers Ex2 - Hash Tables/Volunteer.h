#pragma once

#include "AbstractHashTable.h"
#include<string>
#include<iostream>
using namespace std;

class Volunteer
{
public:
	string name;
	string address;
	int phone;
	string city;

	Volunteer() {};
	Volunteer(string name_, string address_, int phone_, string city_);
	~Volunteer() {};
	void operator=(Volunteer& temp);
	bool operator==(Volunteer& temp);

	friend ostream& operator<<(ostream& out, Volunteer& ob); 
	friend istream& operator>>(istream& in, Volunteer& ob);	
};
//constructor
Volunteer::Volunteer(string name_, string address_, int phone_, string city_)
{
	name = name_;
	address = address_;
	phone = phone_;
	city = city_;
}
// operator =
void Volunteer::operator=(Volunteer& temp)
{
	this->name = temp.name;
	this->address = temp.address;
	this->phone = temp.phone;
	this->city = temp.city;
}
//operator ==
bool Volunteer::operator==(Volunteer& temp)
{
	if (this->name == temp.name) return 1;
	else return 0;
}
//operator cin
istream& operator>>(istream& in, Volunteer& ob)
{
	in >> ob.name >> ob.address >> ob.phone >> ob.city;
	return in;
}
//operator out
ostream& operator<<(ostream& out, Volunteer& ob)
{
	out << ob.name << ob.address << ob.phone << ob.city;
	return out;
}
