#pragma core
#include "Movie.h"

class MovieSeries {
    int ct;
    Movie* movies[16];
public:
    void Init();
    void addMovie(Movie* movie);
    void print();
    void sort();
};
