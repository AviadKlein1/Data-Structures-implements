

#include "AbstractHashTable.h"
#include "ClientHashTable.h"
#include "VolunteerHashTable.h"
#include <list>
#include <string>
#include<iostream>

using namespace std;

class Repository :public ClientHashTable, public VolunteerHashTable
{
public:
	ClientHashTable* clients  = new ClientHashTable(100) ;
	VolunteerHashTable* volenteers = new VolunteerHashTable(100);

	Repository();
	void addVolunteer(Volunteer v);
	void addClient(Client c);
	void delVolunteer(Volunteer v);
	void addVolunteerToClient(Volunteer v, Client c);
	void listOfVolunteers(Client c);
	void listOfClients(Volunteer v);

};

Repository::Repository()
{
	clients->resetTable();
	volenteers->resetTable();
}

void Repository::addVolunteer(Volunteer v)
{
	volenteers->insert(v, v.name);
}

void Repository::addClient(Client c)
{
	clients->insert(c, c.phone);
}

void Repository::delVolunteer(Volunteer v)
{
	volenteers->delete_(v.name);
}

void Repository::addVolunteerToClient(Volunteer v, Client c)
{
	{
		string vn = v.name;
		string cn = c.name;
		v.clients.push_back(vn);
		c.volunteers.push_back(cn);
	}
}

void Repository::listOfVolunteers(Client c)
{
	cout << "The volunteers that helped to client " << c.name << ":";
	int x  = clients->search(c.phone);

	/*for (list<string>::iterator iter = c.volunteers.begin(); iter != c.volunteers.end(); iter++)
		cout << iter << endl;*/

}

void Repository::listOfClients(Volunteer v)
{
	cout << "The clients that were helped by volunteer " << v.name << ":";
	for (list<string>::iterator iter = v.clients.begin(); iter != v.clients.end(); iter++)
	cout << *iter << endl;
}



