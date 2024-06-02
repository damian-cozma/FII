#include "Sentence.h"
#include <iostream>

using namespace std;

Sentence &Sentence::operator+=(Procesor* obj) {
    procesators.push_back(obj);
    return *this;
}

void Sentence::RunAll() {
    for (auto i: procesators)
    {
        cout << "Name:" << i->GetName() << " => " <<  i->Compute(name) << endl;
    }
}

void Sentence::ListAll() {
    for (auto i: procesators)
    {
        cout << "Name:" <<  i->GetName()<< endl;
    }
}

void Sentence::Run(string str) {
    for (auto i: procesators)
    {
        if (i->GetName() == str)
        {
            cout << i->Compute(name);
        }
    }
}
