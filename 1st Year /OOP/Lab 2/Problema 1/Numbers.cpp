#include "Numbers.h"
#include <cstdio>


void Numbers::Init() {
    this -> count = 0;
}

bool Numbers::Add(int x) {
    if (count >= 10)
        return false;
    this -> numbers[count] = x;
    this -> count = count + 1;
    return true;
}

void Numbers::Sort() {
    int i, j, aux;

    for (i=0; i<count; i++)
    {
        for (j=i+1; j<count; j++)
        {
            if (numbers[i] > numbers[j])
            {
                aux=numbers[i];
                numbers[i]=numbers[j];
                numbers[j]=aux;
            }
        }
    }
}

void Numbers::Print() {
    for (int i=0; i<count; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}




