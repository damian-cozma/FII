#include "FerrariRosu.h"

FerrariRosu::FerrariRosu() {
    this->color=(string)"rosu";
}

string FerrariRosu::GetColor() {
    return this->color;
}

string FerrariRosu::GetName() {
    return (string)"Ferrari";
}
