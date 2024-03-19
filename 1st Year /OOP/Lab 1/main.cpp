#define _CRT_SECURE_NO_WARNINGS
#include <cstdio> 
#include <cstring>
using namespace std;

int main()
{
    FILE* fp;
    int suma = 0;
    char num[100];

    fp = fopen("in.txt", "r");

    while (fgets(num, sizeof(num), fp))
    {
        int nr = 0;

        for (int i = 0; i < strlen(num); i++)
        {
            if (num[i] >= '0' && num[i] <= '9')
            {
                nr = nr * 10 + (num[i] - '0');
            }
        }
        suma += nr;
    }

    printf("%d", suma);

    fclose(fp);

    return 0;
}

//Damian Cozma - March 2024
