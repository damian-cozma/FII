#pragma once
#include "Masina.h"
#include <vector>

class Parcare {
    int max, capacity;
    vector<Masina*> masini;
public:
    void Create(int max);
    bool Add(Masina* nume);
    void RemoveByName(string name);
    int GetCount();
    bool IsFull();
    void ShowAll();
    void ShowByColor(string color);
};
