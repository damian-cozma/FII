#include "Toyota.h"

Toyota::Toyota(string color) {
    this->color=color;
}

string Toyota::GetColor() {
    return this->color;
}

string Toyota::GetName() {
    return (string)"Toyota";
}
