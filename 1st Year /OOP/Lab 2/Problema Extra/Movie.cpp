#include "Movie.h"

void Movie::setName(const char *newName) {
    int i = 0;
    while (newName[i] != '\0')
    {
        i++;
    }

    this -> name = new char[i+1];

    i = 0;

    while (newName[i] != '\0')
    {
        name[i] = newName[i];
        i++;
    }
}

const char* Movie::getName() {
    return name;
}

void Movie::setYear(int newYear) {
    this -> year = newYear;
}

int Movie::getYear() {
    return year;
}

void Movie::setIMDB(double newScore) {
    this -> score = newScore;
}

double Movie::getIMDB() {
    return score;
}

void Movie::setLenght(int newLenght) {
    this -> length = newLenght;
}

int Movie::getLenght() {
    return length;
}

int Movie::getYears() {
    return (2024-year);
}




