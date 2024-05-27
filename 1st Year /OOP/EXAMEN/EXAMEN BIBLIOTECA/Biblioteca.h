#pragma once
#include "Carte.h"
#include <vector>

using namespace std;

class Biblioteca{
    vector<Carte*> carti;
    int count;
public:
    Biblioteca();
    ~Biblioteca();
    Biblioteca& operator+=(Carte* book);
    vector<Carte*>::iterator begin();
    vector<Carte*>::iterator end();
    operator int();
    void PrintFilter(std::function<bool(Carte*)> filterFunction);
};
