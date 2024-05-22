#include "Zoo.h"
#include "Feline.h"
#include <vector>

vector<Animal *> Zoo::GetFishes() {
    vector<Animal*> toReturn;

    for (auto i: animals)
    {
        if (i->IsAFish())
        {
            toReturn.push_back(i);
        }
    }

    return toReturn;
}

vector<Animal *> Zoo::GetBirds() {
    vector<Animal*> toReturn;

    for (auto i: animals)
    {
        if (i->IsABird())
        {
            toReturn.push_back(i);
        }
    }

    return toReturn;
}

vector<Animal *> Zoo::GetMammals() {
    vector<Animal*> toReturn;

    for (auto i: animals)
    {
        if (i->IsAMammal())
        {
            toReturn.push_back(i);
        }
    }

    return toReturn;
}

vector<Feline *> Zoo::GetFelines() {
    vector<Feline*> toReturn;

    for (auto i: animals)
    {
        if (i->GetName() == "Lion" or i->GetName() == "Tiger")
        {
            toReturn.push_back((Feline*)i);
        }
    }

    return toReturn;
}

int Zoo::GetTotalAnimals() {
    return animals.size();
}

void Zoo::operator+=(Animal *i) {
    animals.push_back(i);
}

bool Zoo::operator()(string name) {
    for (auto i: animals)
    {
        if(i->GetName() == name) return true;
    }
    return false;
}




