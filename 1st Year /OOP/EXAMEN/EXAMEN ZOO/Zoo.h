#pragma once
#include <vector>
#include "Animal.h"
#include "Feline.h"

class Zoo {
    vector<Animal*> animals;
public:
    vector<Animal*> GetFishes();
    vector<Animal*> GetBirds();
    vector<Animal*> GetMammals();
    vector<Feline*> GetFelines();

    int GetTotalAnimals();
    void operator+=(Animal*);
    bool operator()(string name);
};
