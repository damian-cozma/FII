#pragma once
#include <string>
#include "Masina.h"

using namespace std;

class Toyota : public Masina {
private:
    string color;
public:
    Toyota(string color);
    string GetColor();
    string GetName();
};
