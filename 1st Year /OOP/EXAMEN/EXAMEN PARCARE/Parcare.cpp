#include "Parcare.h"
#include "Masina.h"
#include <iostream>
#include <vector>

using namespace std;

void Parcare::Create(int max) {
    this->max=max;
    this->capacity=0;
}

bool Parcare::Add(Masina* nume) {
    if (capacity<max)
    {
        masini.push_back(nume);
        capacity++;
        return true;
    }
    return false;
}

//REVISE
void Parcare::RemoveByName(string name) {
    for (auto i = masini.begin(); i <= masini.end(); i++)
    {
        if ((*i)->GetName() == name)
        {
            masini.erase(i);
            capacity--;
        }
    }
}


int Parcare::GetCount() {
    return this->capacity;
}

bool Parcare::IsFull() {
    if (capacity==max)
    {
        return true;
    }
    return false;
}

void Parcare::ShowAll() {
    cout <<"SHOW-ALL:";
    for (auto i: masini)
    {
        cout << i->GetName() << "(" << i->GetColor() << "),";
    }
    cout << endl;
}

void Parcare::ShowByColor(string color) {
    cout <<"SHOW-COLOR: (" << color << "):";
    for (auto i: masini)
    {
        if (i->GetColor() == color)
        cout << i->GetName() << ",";
    }
    cout << endl;
}
