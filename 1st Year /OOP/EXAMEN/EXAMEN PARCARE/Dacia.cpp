#include "Dacia.h"

Dacia::Dacia(string color) {
    this->color=color;
}

string Dacia::GetColor() {
    return this->color;
}

string Dacia::GetName() {
    return (string)"Dacia";
}
