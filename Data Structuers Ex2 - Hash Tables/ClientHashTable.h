
#include "AbstractHashTable.h"
#include "Volunteer.h"
#include "Client.h"
#include<string>
#include<iostream>

using namespace std;

class ClientHashTable :public AbstractHashTable <Client, int>
{
public:
    ClientHashTable() { };
    ClientHashTable(int size) :AbstractHashTable(size) {};
    int h1(int k);
    int h2(int k);
    void resetTable();
    void print();

};
//h1 func
int ClientHashTable::h1(int k) {

    return k % lenghtHashTable;
}
//h2 func
int ClientHashTable::h2(int k)
{
    return (k + 1) % lenghtHashTable;
}

void ClientHashTable::resetTable()
{
    for (int i = 0; i < lenghtHashTable; i++) { //resets the new places with empty condition
        this->hashTable[i].flag = empty_;
    }
}
void ClientHashTable::print()
{
    for (int i = 0; i < lenghtHashTable; i++) {
        try {
            if (hashTable[i].flag != empty_)cout << hashTable[i].data;
        }
        catch (...) {}
    }
}