#pragma once

#include "AbstractHashTable.h"
#include "volunteer.h"
#include "client.h"
#include<string>
#include<iostream>

using namespace std;

class ClientHashTable :AbstractHashTable <client, int>
{
    ClientHashTable() { };
    ClientHashTable(int size) :AbstractHashTable(size) {};
    int h1(int k);
    int h2(int k);
    void startNewTable();
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
