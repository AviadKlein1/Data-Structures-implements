#pragma once

#include "AbstractHashTable.h"
#include "Client.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Volunteer
{
public:
	string name;
	string address;
	int phone;
	//string city;
	list <string> clients;

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
	//city = city_;
}
// operator =
void Volunteer::operator=(Volunteer& temp)
{
	this->name = temp.name;
	this->address = temp.address;
	this->phone = temp.phone;
	//this->city = temp.city;
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
	cout << "Enter volunteer name, phone, address:\n ";
	in >> ob.name >> ob.phone >> ob.address; /*>> ob.city*/
	return in;
}
//operator out
ostream& operator<<(ostream& out, Volunteer& ob)
{
	out << ob.name << ": volunteer name =" << ob.name << " phone =" << ob.phone << " address =" << ob.address << endl;
	if (!(ob.clients.empty()))
	{
		for (list<string>::iterator iter = ob.clients.begin(); iter != ob.clients.end(); iter++)
			cout << *iter << endl;
	}
	return out;
}
