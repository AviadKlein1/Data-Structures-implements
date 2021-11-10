#pragma once
#include "Item.h"

using namespace std;

template<class T, class K>
class AbstractHashTable {
protected:
    Item <T, K>* hashTable;
    int lenghtHashTable;
public:
    AbstractHashTable() {};
    AbstractHashTable(int size);
    ~AbstractHashTable();
    virtual int h1(K k) = 0; //Pure virtual 
    virtual int h2(K k) = 0; //Pure virtual
    int hash(K, int);
    int search(K);
    void insert(T, K);
    void delete_(K);
    void update(T, K);
    virtual void print() {};
    bool find(K);
};

bool isPrime(int n)
{
    // Corner cases  
    if (n <= 3)  return true;

    // This is checked so that we can skip middle five numbers in below loop  
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
int nextPrime(int N) {

    if (N <= 0) {
        throw "Invalid Number";
    }
    if (N == 1) // Base case 
        return 2;

    int prime = N;
    bool found = false;

    while (!found) {// Loop continuously until isPrime returns 
        prime++;

        if (isPrime(prime))
            found = true; // true for a number greater than n 
    }
    return prime;
}

//constructor
template <class T, class K>
AbstractHashTable <T, K>::AbstractHashTable(int size)
{
    lenghtHashTable = nextPrime(size); //finds the next prime number
    hashTable = new Item<T, K>[lenghtHashTable]; //creates the array with the correct size
    for (int i = 0; i < lenghtHashTable; i++)
        hashTable[i].flag = empty_;
}
//destructor
template<class T, class K>
AbstractHashTable<T, K>::~AbstractHashTable()
{
    if (hashTable)
    {
        delete[]hashTable; //delets the array
    }
}
//Hash func
template <class T, class K>
int AbstractHashTable<T, K>::hash(K key, int i) {
    return ((h1(key) + i * h2(key)) % lenghtHashTable); //calculate where to set the key by the staking function 1 and 2
}
//search
template <class T, class K>
int AbstractHashTable < T, K>::search(K k)
{
    int i = 0;
    int x = hash(k, i); //finds the key place
    while (i != lenghtHashTable && hashTable[x].flag != empty_) //we did not get to the end or found sn empty place
    {
        x = hash(k, i);
        if (hashTable[x].key == k && hashTable[x].flag == full) //if the key was found
            return x;
        i++;
    }
    return -1; //it was not found
}
//insert 
template <class T, class K>
void AbstractHashTable<T, K>::insert(T d, K k)
{
    int i = 0;
    int x;
    while (i != lenghtHashTable)
    {
        x = hash(k, i);
        if (hashTable[x].flag == empty_ || hashTable[x].flag == deleted) //if there is place to insert
        {
            //update the data, key and condition
            hashTable[x].key = k;
            hashTable[x].data = d;
            hashTable[x].flag = full;
            return;
        }
        i++;
    }
    throw "ERROR";
}
//delete
template <class T, class K>
void AbstractHashTable<T, K>::delete_(K k)
{
    int index = search(k); //finds the key place
    if (index != -1)
    { //it was found
        hashTable[index].flag = deleted;
        return;
    }
    else
    {
        cout << "ERROR" << endl;
    }
}
//update
template <class T, class K>
void AbstractHashTable<T, K>::update(T data, K key)
{
    int index = search(key); //finds the key place
    if (index != -1)  //it was found
    {
        hashTable[index].data = data; //update the data
    }
}
//bool - find
template <class T, class K>
bool AbstractHashTable<T, K>::find(K k) {
    int i = 0;
    int x = hash(k, i); //finds the key place
    while (i != lenghtHashTable && hashTable[x].flag != empty_)
    {
        x = hash(k, i);
        if (hashTable[x].key == k && hashTable[x].flag == full) //if the key was found return true
        {
            return true;
        }
        i++;
    }
    return false;
}