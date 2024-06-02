#pragma once
#include "Procesor.h"

class LongestWord : public Procesor{
    string nume;
public:
    LongestWord(string nume) : nume(nume) {};

    string GetName(){
        return this->nume;
    }

    int Compute(string nume){
        int ct = 0, ctMax = 0;

        for (auto i=nume.begin(); i!=nume.end(); i++)
        {
            if ((*i) != ' ')
            {
                ct++;
            }
            else if ((*i) == ' ')
            {
                if (ct > ctMax)
                {
                    ctMax = ct;
                }
                ct = 0;
            }
        }
        return ctMax;
    }
};
