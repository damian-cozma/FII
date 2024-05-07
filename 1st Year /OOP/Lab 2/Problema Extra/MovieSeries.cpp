#include "MovieSeries.h"
#include <cstdio>

void MovieSeries::Init() {
    this -> ct = 0;
}

void MovieSeries::addMovie(Movie *movie) {
    if (ct <= 16)
    {
        movies[ct++] = movie;
    }
}

void MovieSeries::print() {
    int i;
    for (i=0; i<ct; i++)
    {
        printf("FILM: %s, AN: %d, IMDB: %g, DURATA: %d, L: %d\n", movies[i]->getName(), movies[i]->getYear(), movies[i]->getIMDB(), movies[i]->getLenght(), movies[i]->getYears());
    }
}

void MovieSeries::sort() {
    int i, j;
    for (i=0; i<ct; i++)
    {
        for (j=i+1; j<ct; j++)
        {
            if (movies[i]->getYears() < movies[j]->getYears())
            {
                Movie* temp = movies[j];
                movies[j] = movies[i];
                movies[i] = temp;
            }
        }
    }
}


