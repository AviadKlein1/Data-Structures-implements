
#include "AbstractHashTable.h"
#include "Volunteer.h"
#include "Client.h"
#include<string>
#include<iostream>

using namespace std;

class VolunteerHashTable :public AbstractHashTable <Volunteer, string>
{
public:
    VolunteerHashTable() { };
    VolunteerHashTable(int size) :AbstractHashTable(size) {};
    int h1(string k);
    int h2(string k);
    void resetTable();
    void printCli(string);
    void print();
    void update(string name, string client);
};
//h1 func
int VolunteerHashTable::h1(string k)
{

    return k.length() % lenghtHashTable;
}
//h2 func
int VolunteerHashTable::h2(string k)
{
    return (k.length() + 1) % lenghtHashTable;
}
