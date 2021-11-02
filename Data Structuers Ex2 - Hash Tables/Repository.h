

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
	ClientHashTable* clients = new ClientHashTable(100);
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
	volenteers->update(v.name, c.phone);

	//volunteers that help to client
	
	clients->update(c.phone, v.name);
}

void Repository::listOfVolunteers(Client c)
{
	clients->printVol(c.phone);
}

void Repository::listOfClients(Volunteer v)
{
	volenteers->printCli(v.name);
}




