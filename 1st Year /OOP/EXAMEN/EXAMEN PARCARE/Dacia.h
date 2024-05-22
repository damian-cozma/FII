#pragma once
#include <string>
#include "Masina.h"

using namespace std;

class Dacia : public Masina {
private:
    string color;
public:
    Dacia(string color);
    string GetColor();
    string GetName();
};
