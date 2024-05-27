#pragma once
#include "Carte.h"
#include <iostream>

using namespace std;

class Roman : public Carte{
    string nume, autor;
public:
    Roman(string nume, string autor) : nume(nume), autor(autor) {};

    string GetInfo(){
        return "Roman " + this->nume + " de " + this->autor;
    }
};
