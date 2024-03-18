#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	cout << "#1" << endl;
	Sort s1(10, 1, 100);
	s1.Print(); s1.BubbleSort(); s1.Print();
	cout << endl;

	cout << "#2" << endl;
	int* vec = new int[11] {1, 4, 3, 2, 5, 8, 6, 9, 10, 7, -1};
	Sort s2(vec);
	s2.Print(); s2.InsertSort(); s2.Print();
	cout << endl;

	cout << "#3" << endl;
	int v[10] = {3, 24, 5, 12, 53, 6, 34, 88, 9, 10};
	Sort s3(10, v);
	s3.Print(); s3.QuickSort(); s3.Print();
	cout << endl;

	cout << "#4" << endl;
	Sort s4(3, 1, 2, 3);
	s4.Print(); s4.BubbleSort(); s4.Print();
	cout << endl;

	cout << "#5" << endl;
	char numere[] = "3,24,5,12,53,6,34,88,9,10";
	cout << numere << endl;
	Sort s5(numere);
	s5.Print(); s5.QuickSort(); s5.Print();
}

//Damian Cozma - March 2024
