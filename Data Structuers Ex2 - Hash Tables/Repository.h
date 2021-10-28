#pragma once
#include "AbstractHashTable.h"
#include "ClientHashTable.h"
#include "VolunteerHashTable.h"

#include<iostream>

using namespace std;

class Repository :ClientHashTable, VolunteerHashTable
{
public:
	Repository();	
};
