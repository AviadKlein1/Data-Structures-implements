#pragma once

#include "AbstractHashTable.h"
#include "volunteer.h"
#include<string>
#include<iostream>

using namespace std;

class volunteerHashTable :AbstractHashTable <volunteer, string>
{
    volunteerHashTable() { };
    volunteerHashTable(int size) :AbstractHashTable(size) {};
    int h1(string k);
    int h2(string k);
    void startNewTable();
    void print();

};
//h1 func
int volunteerHashTable::h1(string k) {

    return k.length() % lenghtHashTable;
}
//h2 func
int volunteerHashTable::h2(string k)
{
    return (k.length() + 1) % lenghtHashTable;
}
