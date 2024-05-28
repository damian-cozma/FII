#pragma once
#include "Entry.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class IntegerData : public Entry{
    int value;
public:
    IntegerData(string name, string value) : Entry(name) {
        this->value=stoi(value);
    }

    void Add(string toAdd){
        this->value+=stoi(toAdd);
    }

    bool Substract(int toSubstract){
        if (this->value < toSubstract)
        {
            cout << "IntegerData: " << value << " < " << toSubstract << endl;
            return false;
        }

        this->value-=toSubstract;
        return true;
    }

    void Print(){
        cout << GetName() << " = " << this->value << ";";
    }
};
