#pragma once
#include <vector>
#include <string>
#include "Procesor.h"

using namespace std;

class Sentence {
    vector<Procesor*> procesators;
    string name;
public:
    Sentence(string s) : name(s) {};
    void RunAll();
    void ListAll();
    void Run(string name);
    Sentence& operator+=(Procesor* obj);
};
