// Aviad Klein 315552679
// Tomer Peretz 314083080
// Data Structures
// Exercise 2

#include <iostream>
#include <string>
#include <list>
#include "Client.h"
#include "Volunteer.h"
#include "Repository.h"

using namespace std;

int main()
{
	char ch;
	Volunteer v;
	Client c;
	Repository ht;
	list<Volunteer*> lst;

	cout << "Hash Tables\n";
	do
	{
		cout << "\nChoose one of the following" << endl;
		cout << "n: New volunteer" << endl;
		cout << "d: Del a volunteer " << endl;
		cout << "c: New client" << endl;
		cout << "l: Add a connection volunteer-client " << endl;
		cout << "*: Print volunteers that helped a client " << endl;
		cout << "i: Print clients that were helped by a voluneer " << endl;
		cout << "p: Print hash tables" << endl;
		cout << "e: Exit" << endl;
		cin >> ch;
		switch (ch)
		{
		case 'n': cin >> v; ht.addVolunteer(v); break;
		case 'd': cout << "enter volunteer name "; cin >> v.name; ht.delVolunteer(v); break;
		case 'c': cin >> c; ht.addClient(c); break;
		case 'l': cout << "enter volunteer name and client phone "; cin >> v.name >> c.phone; ht.addVolunteerToClient(v, c); break;
		case '*': cout << "enter client phone ";  cin >> c.phone; ht.listOfVolunteers(c); break;
		case 'i': cout << "enter volunteer name "; cin >> v.name; break;
		case 'p': cout << "Volunteers:\n"; ht.volenteers->print(); cout << "Clients:\n"; ht.clients->print(); break;
		case 'e':cout << "bye "; break;
		default: cout << "Error ";  break;
		}
	} while (ch != 'e');
	return 0;
}

/*
running example:
Hash Tables

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
e
bye
*/