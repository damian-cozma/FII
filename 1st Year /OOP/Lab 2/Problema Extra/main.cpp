#include <cstdio>
#include "Movie.h"
#include "MovieSeries.h"
#include "functions.h"

using namespace std;

int main() {
    Movie ep5;
    ep5.setName("Star Wars: Episode V - The Empire Strikes Back");
    ep5.setIMDB(8.7);
    ep5.setYear(1980);
    ep5.setLenght(124);

    Movie ep4;
    ep4.setName("Star Wars: Episode IV - A New Hope");
    ep4.setIMDB(8.6);
    ep4.setYear(1977);
    ep4.setLenght(121);

    Movie ep6;
    ep6.setName("Star Wars: Episode VI - Return of the Jedi");
    ep6.setIMDB(8.3);
    ep6.setYear(1983);
    ep6.setLenght(131);

    printf(
            R"(
ep4, ep5 comparisons:
name        : %d
year        : %d
score       : %d
length      : %d
passed years: %d
)",
            compName(ep4, ep5),
            compYear(ep4, ep5),
            compIMDB(ep4, ep5),
            compLenght(ep4, ep5),
            compPassed(ep4, ep5));

    MovieSeries series;
    series.Init();
    series.addMovie(&ep5);
    series.addMovie(&ep4);
    series.addMovie(&ep6);

    series.sort();
    series.print();
}
