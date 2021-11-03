
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
    void printS(string);
    void print();

};
//h1 func
int VolunteerHashTable::h1(string k) {

    return k.length() % lenghtHashTable;
}
//h2 func
int VolunteerHashTable::h2(string k)
{
    return (k.length() + 1) % lenghtHashTable;
}
void VolunteerHashTable::resetTable()
{
    for (int i = 0; i < lenghtHashTable; i++) { //resets the new places with empty condition
        this->hashTable[i].flag = empty_;
    }
}

void VolunteerHashTable::print()
{
    for (int i = 0; i < lenghtHashTable; i++) {
        try {
            if (hashTable[i].flag != empty_)cout << hashTable[i].data;
        }
        catch (...) {}
    }
}
