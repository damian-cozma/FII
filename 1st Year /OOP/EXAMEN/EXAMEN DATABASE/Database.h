#pragma once
#include <vector>
#include "Entry.h"

using namespace std;

class Database{
    vector<Entry*> entries;
public:
    Database& operator+=(Entry* obj);
    Database& operator-=(string remove);
    vector<Entry*>::iterator begin();
    vector<Entry*>::iterator end();
    void Print();
};
