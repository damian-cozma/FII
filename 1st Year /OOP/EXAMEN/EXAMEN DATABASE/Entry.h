#pragma once
#include "Database.h"
#include <string>

using namespace std;

class Entry{
private:
    string name;
public:
    Entry(string name) : name(name) {};

    string GetName(){
        return name;
    };

    virtual void Add(string toAdd) = 0;
    virtual bool Substract(int toSubstract) = 0;
    virtual void Print() = 0;
};
