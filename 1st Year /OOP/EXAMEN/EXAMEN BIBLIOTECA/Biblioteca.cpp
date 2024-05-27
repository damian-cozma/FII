#include "Biblioteca.h"
#include <iostream>

using namespace std;

Biblioteca::Biblioteca() {
    count = 0;
}

Biblioteca::~Biblioteca() {
}


Biblioteca& Biblioteca::operator+=(Carte* book) {
    this->count++;
    carti.push_back(book);
    return *this;
}

vector<Carte*>::iterator Biblioteca::begin() {
    return carti.begin();
}

vector<Carte*>::iterator Biblioteca::end() {
    return carti.end();
}

Biblioteca::operator int() {
    return carti.size();
}

void Biblioteca::PrintFilter(std::function<bool(Carte*)> filterFunction) {
    for (auto carte : carti) {
        if (filterFunction(carte)) {
            cout << carte->GetInfo() << endl;
        }
    }
}
