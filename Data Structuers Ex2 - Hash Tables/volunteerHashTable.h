
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
    void update(string name, int clientPhone);
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
void VolunteerHashTable::printCli(string name)
{
    int index = search(name);
    int sum = hashTable[index].data.numOfCli;
    cout << "The volunteers that helped to client " << name <<": ";
    for (int i = 0; i < sum; i++)
        cout << hashTable[index].data.cli[i] << " ";
    cout << endl;
}

void VolunteerHashTable::update(string name, int clientPhone)
{
    int index = search(name); //finds the key place
    if (index != -1)  //it was found
    {
        hashTable[index].data.cli[hashTable[index].data.numOfCli] = clientPhone; //update the data
        hashTable[index].data.numOfCli++;
    }
}