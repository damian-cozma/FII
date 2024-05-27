#pragma once
#include "Carte.h"

using namespace std;

class Revista : public Carte{
    string titlu;
    int nrArticole;
public:
    Revista(string titlu, int nrArticole) : titlu(titlu), nrArticole(nrArticole) {};

    string GetInfo(){
        return "Revista " + this->titlu + " cu " + to_string(this->nrArticole) + " articole";
    }
};
