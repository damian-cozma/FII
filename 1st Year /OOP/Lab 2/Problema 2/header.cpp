#include "header.h"
#include <cstdio>
#include <cstring>
#include <iostream>

void header::setNume(const char *newName) {
    int i = 0;
    while (newName[i] != '\0')
    {
        i++;
    }

    this -> nume = new char[i+1];

    i = 0;
    while (newName[i] != '\0')
    {
        nume[i] = newName[i];
        i++;
    }
}

const char* header::getNume() {
    return this -> nume;
}

void header::setMate(float nota) {
    this -> mate = nota;
}

void header::setEng(float nota) {
    this -> eng = nota;
}

void header::setIst(float nota) {
    this -> ist = nota;
}

float header::getMate() {
    return this->mate;
}

float header::getEng() {
    return this->eng;
}

float header::getIst() {
    return this->ist;
}

void header::setAverage() {
    this -> average = (mate+eng+ist)/3;
}

float header::getAverage() {
    return this -> average;
}


