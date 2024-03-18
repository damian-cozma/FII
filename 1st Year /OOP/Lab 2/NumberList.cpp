#include "NumberList.h"
#include <iostream>

using namespace std;

void NumberList::Init()
{
	this -> count = 0;
}

bool NumberList::Add(int x)
{
	if (this -> count < 10)
	{
		numbers[count] = x;
		count++;
		return true;
	}
	return false;
}

void NumberList::Sort()
{
	int ultim = count - 1, n1;
	while (ultim > 0)
	{
		n1 = ultim - 1;
		ultim = 0;

		for (int i = 0; i <= n1; i++)
		{
				if (numbers[i] > numbers[i + 1])
				{
						swap(numbers[i], numbers[i + 1]);
						ultim = i;
				}
		}
	}
}

void NumberList::Print()
{
	for (int i = 0; i < count; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << std::endl;
}

//Damian Cozma - March 2024
