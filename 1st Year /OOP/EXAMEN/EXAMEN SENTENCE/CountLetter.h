#pragma once
#include "Procesor.h"

class CountLetter : public Procesor{
    string nume;
    bool (*predicate)(char);
public:
    CountLetter(std::string nume, bool (*predicate)(char)): nume(nume), predicate(predicate) {}

    string GetName(){
        return this->nume;
    }

    int Compute(std::string str) {
        int count = 0;
        for (char ch : str) {
            if (predicate(ch)) {
                ++count;
            }
        }
        return count;
    }
};
