#pragma once
#include "Procesor.h"

class ComputeVowals : public Procesor{
    string nume;
public:
    ComputeVowals(string nume) : nume(nume) {};

    string GetName(){
        return this->nume;
    }

    int Compute(string nume){
        int ct = 0;
        for (auto i=nume.begin(); i!=nume.end(); i++)
        {
            if ((*i) == 'A' or (*i) == 'E' or (*i) == 'e' or (*i) == 'I' or (*i) == 'i' or (*i) == 'O' or (*i) == 'o' or (*i) == 'U' or (*i) == 'u' or (*i) == 'a')
            {
                ct++;
            }
        }
        return ct;
    }
};
