#pragma once

#include "AbstractHashTable.h"
#include<string>
#include<iostream>
using namespace std;

class volunteer
{
public:
	string name;
	string address;
	int phone;
	string city;

	volunteer() {};
	volunteer(string name_, string address_, int phone_, string city_);
	~volunteer() {};
	void operator=(volunteer& temp);
	bool operator==(volunteer& temp);

	friend ostream& operator<<(ostream& out, volunteer& ob); 
	friend istream& operator>>(istream& in, volunteer& ob);	
};
//constructor
volunteer::volunteer(string name_, string address_, int phone_, string city_)
{
	name = name_;
	address = address_;
	phone = phone_;
	city = city_;
}
// operator =
void volunteer::operator=(volunteer& temp)
{
	this->name = temp.name;
	this->address = temp.address;
	this->phone = temp.phone;
	this->city = temp.city;
}
//operator ==
bool volunteer::operator==(volunteer& temp)
{
	if (this->name == temp.name) return 1;
	else return 0;
}
//operator cin
istream& operator>>(istream& in, volunteer& ob)
{
	in >> ob.name >> ob.address >> ob.phone >> ob.city;
	return in;
}
//operator out
ostream& operator<<(ostream& out, volunteer& ob)
{
	out << ob.name << ob.address << ob.phone << ob.city;
	return out;
}
