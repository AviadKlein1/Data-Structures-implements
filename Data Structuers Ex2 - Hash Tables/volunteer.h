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
	string cli[10];
	int numOfCli = 0;

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
	this->numOfCli = temp.numOfCli;
	for (int i = 0; i <= numOfCli; i++)
		this->cli[i] = temp.cli[i];
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
	in >> ob.name >> ob.phone >> ob.address;
	return in;
}
//operator out
ostream& operator<<(ostream& out, Volunteer& ob)
{
	out << ob.name << ": volunteer name = " << ob.name << " phone = " << ob.phone << " address = " << ob.address;
	/*if (ob.numOfCli)
	{
		cout << "helped by:";
		for (int i = 0; i < ob.numOfCli; i++)
			cout << ob.cli[i] << " ";
	}*/
	cout << endl;
	return out;
}
