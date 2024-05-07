#pragma once

class Movie
{
    char* name;
    int year, length;
    double score;
public:
    void setName(const char* newName);
    const char* getName();
    void setYear(int newYear);
    int getYear();
    void setIMDB(double newScore);
    double getIMDB();
    void setLenght(int newLenght);
    int getLenght();
    int getYears();
};
