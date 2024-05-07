#include "functions.h"

int compName(Movie a, Movie b)
{
    const char* unu;
    const char* doi;

    unu = a.getName();
    doi = b.getName();

    int i = 0, j = 0;

    while (unu[i] != '\0')
    {
        i++;
    }

    while (doi[j] != '\0')
    {
        j++;
    }

    if (i == j) return 0;
    else if (i > j) return 1;
    else return -1;
}

int compYear(Movie a, Movie b)
{
    if (a.getYear() == b.getYear())
    {
        return 0;
    }
    else if (a.getYear() > b.getYear())
    {
        return 1;
    }
    else return -1;
}

int compIMDB(Movie a, Movie b)
{
    if (a.getIMDB() == b.getIMDB())
    {
        return 0;
    }
    else if (a.getIMDB() > b.getIMDB())
    {
        return 1;
    }
    else return -1;
}

int compLenght(Movie a, Movie b)
{
    if (a.getLenght() == b.getLenght())
    {
        return 0;
    }
    else if (a.getLenght() > b.getLenght())
    {
        return 1;
    }
    else return -1;
}

int compPassed(Movie a, Movie b)
{
    if (a.getYears() == b.getYears())
    {
        return 0;
    }
    else if (a.getYears() > b.getYears())
    {
        return 1;
    }
    else return -1;
}
