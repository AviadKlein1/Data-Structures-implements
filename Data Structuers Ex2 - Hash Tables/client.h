#include "AbstractHashTable.h"
#include<string>
#include<list>
#include<iostream>
#include "volunteer.h"

using namespace std;

class client
{
public:
	string name;
	string address;
	int phone;
	list<volunteer> volunteers;

	client() {};
	client(string name_, string address_, int phone_);
	~client() {};
	void operator=(client& temp);
	bool operator==(client& temp);

	friend ostream& operator<<(ostream& out, client& ob);
	friend istream& operator>>(istream& in, client& ob);
};
//constructor
client::client(string name_, string address_, int phone_)
{
	name = name_;
	address = address_;
	phone = phone_;
}
// operator =
void client::operator=(client& temp)
{
	this->name = temp.name;
	this->address = temp.address;
	this->phone = temp.phone;
}
//operator ==
bool client::operator==(client& temp)
{
	if (this->name == temp.name) return 1;
	else return 0;
}
//operator cin
istream& operator>>(istream& in, client& ob)
{
	in >> ob.name >> ob.address >> ob.phone;
	return in;
}
//operator out
ostream& operator<<(ostream& out, client& ob)
{
	out << ob.name << ob.address << ob.phone << "\n volunteers:\n";
	for (list<volunteer>::iterator iter = ob.volunteers.begin(); iter != ob.volunteers.end(); iter++)
		cout << (iter)->name <<endl;

	return out;
}
