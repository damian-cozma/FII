#pragma once
#include "Entry.h"
#include <iostream>
using namespace std;

class StringData : public Entry{
    string value;
public:
    StringData(string name, string value) : Entry(name), value(value) {};
    void Add(string toAdd){
        value.append(toAdd);
    }
    bool Substract(int toSubstract){
        if (value.size() < toSubstract)
        {
            cout << "StringData: len(" << value << ") < " << toSubstract << endl;
            return false;
        }

        value.erase(value.size() - toSubstract);
        return true;
    }
    void Print(){
        cout << GetName() << " = " << this->value << ";";
    }
};
