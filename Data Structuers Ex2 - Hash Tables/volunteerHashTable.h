#pragma once

#include "AbstractHashTable.h"
#include "Volunteer.h"
#include<string>
#include<iostream>

using namespace std;

class VolunteerHashTable :AbstractHashTable <Volunteer, string>
{
    VolunteerHashTable() { };
    VolunteerHashTable(int size) :AbstractHashTable(size) {};
    int h1(string k);
    int h2(string k);
    void startNewTable();
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
