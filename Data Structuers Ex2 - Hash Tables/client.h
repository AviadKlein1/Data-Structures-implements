#pragma once
#include "AbstractHashTable.h"
#include <string>
#include <list>
#include <iostream>
#include "Item.h"


using namespace std;

class Client
{
public:
	string name;
	string address;
	int phone;
	string vol[10];
	int numOfVol = 0;

	Client() {};
	Client(string name_, string address_, int phone_);
	~Client() {};
	void operator=(Client& temp);
	bool operator==(Client& temp);

	friend ostream& operator<<(ostream& out, Client& ob);
	friend istream& operator>>(istream& in, Client& ob);
};
//constructor
Client::Client(string name_, string address_, int phone_)
{
	name = name_;
	address = address_;
	phone = phone_;
}
// operator =
void Client::operator=(Client& temp)
{
	this->name = temp.name;
	this->address = temp.address;
	this->phone = temp.phone;
	this->numOfVol = temp.numOfVol;
	for (int i = 0; i <= numOfVol; i++)
		this->vol[i] = temp.vol[i];
}
//operator ==
bool Client::operator==(Client& temp)
{
	if (this->name == temp.name) return 1;
	else return 0;
}
//operator cin
istream& operator>>(istream& in, Client& ob)
{
	cout << "please enter name and phone and address of client\n";
	in >> ob.name >> ob.phone >> ob.address;
	return in;
}
//operator out
ostream& operator<<(ostream& out, Client& ob)
{
	out << ob.phone << ": client name: " << ob.name << " phone: " << ob.address << " address: " << ob.phone;
	if (ob.numOfVol)
	{
		cout << " helped by: ";
		for (int i = 0; i < ob.numOfVol; i++)
			cout << ob.vol[i] << " ";
	}
	cout << endl;
	return out;
}
