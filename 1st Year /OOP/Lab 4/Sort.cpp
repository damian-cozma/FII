#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cstring>

using namespace std;

Sort::Sort(int n, int min, int max) //1
{
	this -> size = n;
	this -> v = new int[size];
	
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		v[i] = rand() % (max - min + 1) + min;
	}
}

Sort::Sort(int *vec) //2
{
	int c = 0;
	while (vec[c] >= 0)
	{
		c++;
	}

	this -> size = c;
	this -> v = new int[size];

	for (int i = 0; i < size; i++)
	{
		v[i] = vec[i];
	}
}

Sort::Sort(int n, int* vec)
{
	this -> size = n;
	this -> v = new int[size];

	for (int i = 0; i < size; i++)
	{
		v[i] = vec[i];
	}
}

Sort::Sort(int n, ...)
{
	this -> size = n;
	this -> v = new int[size];

	va_list args;
	va_start(args, n);

	for (int i = 0; i < size; i++)
	{
		v[i] = va_arg(args, int);
	}
}

Sort::Sort(char* s)
{
	this -> v = new int[100];
	char* p = strtok(s, ",");
	int ct = 0;

	while (p != NULL)
	{
		v[ct] = atoi(p);
		ct++;
		p = strtok(NULL, ",");
	}
	this->size = ct;
}

void Sort::BubbleSort(bool ascendent)
{
	int ultim = size - 1, n1;
	while (ultim > 0)
	{
		n1 = ultim - 1;
		ultim = 0;

		for (int i = 0; i <= n1; i++)
		{
			if (ascendent)
			{
				if (v[i] > v[i + 1])
				{
					swap(v[i], v[i + 1]);
					ultim = i;
				}
			}
			else
			{
				if (v[i] < v[i + 1])
				{
					swap(v[i], v[i + 1]);
					ultim = i;
				}
			}
		}
	}
}

void Sort::InsertSort(bool ascendent)
{
	int j, aux;
	for (int i = 1; i < size; i++)
	{
		aux = v[i];
		j = i - 1;

		if (ascendent)
		{
			while (j >= 0 && v[j] > aux)
			{
				v[j + 1] = v[j];
				j--;
			}
		}
		else
		{
			while (j >= 0 && v[j] < aux)
			{
				v[j + 1] = v[j];
				j--;
			}
		}
		v[j + 1] = aux;
	}
}

void Sort::QuickSort(bool ascendent)
{
	QuickSort(0, size - 1, ascendent);
}

int Sort::partitionare(int st, int dr, bool ascendent)
{
	int pivot = v[dr];
	int i = st - 1;

	for (int j = st; j < dr; j++)
	{
		if (ascendent)
		{
			if (v[j] < pivot)
			{
				i++;
				swap(v[i], v[j]);
			}
		}
		else
		{
			if (v[j] > pivot)
			{
				i++;
				swap(v[i], v[j]);
			}
		}
	}
	swap(v[i + 1], v[dr]);
	return i + 1;
}

void Sort::QuickSort(int st, int dr, bool ascendent)
{
	if (st < dr)
	{
		int k = partitionare(st, dr, ascendent);
		QuickSort(st, k - 1, ascendent);
		QuickSort(k + 1, dr, ascendent);
	}
}

void Sort::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int Sort::GetElementsCount()
{
	return size;
}

int Sort::GetElementFromIndex(int index)
{
	return v[index];
}
