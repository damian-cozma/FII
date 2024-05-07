#include "header.h"
#include "functions.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    header s1, s2;

    s1.setNume("Maria");
    printf("Utilizator nou: %s\n", s1.getNume());
    s1.setMate(8);
    s1.setIst(7.3);
    s1.setEng(10);

    printf("Notele studentului %s sunt: \n", s1.getNume());
    printf("Matematica: %g\n", s1.getMate());
    printf("Engleza: %g\n", s1.getEng());
    printf("Istorie: %g\n", s1.getIst());

    s1.setAverage();
    printf("Media studentului este: %g\n", s1.getAverage());
    printf("----------------------\n");

    s2.setNume("Alex");
    printf("Utilizator nou: %s\n", s2.getNume());
    s2.setMate(9);
    s2.setIst(10);
    s2.setEng(5);
    printf("Notele studentului %s sunt: \n", s2.getNume());
    printf("Matematica: %g\n", s2.getMate());
    printf("Engleza: %g\n", s2.getEng());
    printf("Istorie: %g\n", s2.getIst());

    s2.setAverage();
    printf("Media studentului este: %g\n", s2.getAverage());
    printf("----------------------\n");

    std::cout << compName(s1, s2) << " ";
    std::cout << compAvg(s1, s2) << " ";
    std::cout << compEng(s1, s2) << " ";
    std::cout << compIst(s1, s2) << " ";
    std::cout << compMate(s1, s2);
}
