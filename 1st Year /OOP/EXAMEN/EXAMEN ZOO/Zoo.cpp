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
    int i;
    vector<Feline*> felines;

    for (auto i : animals)
    {
        Feline* feline = dynamic_cast<Feline*>(i);

        if (feline != nullptr) {
            felines.push_back(feline);
        }
    }

    return felines;
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




