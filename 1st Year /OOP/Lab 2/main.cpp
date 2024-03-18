#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
	NumberList n;
	n.Init();
	n.Add(5);
	n.Add(3);
	n.Add(7);
	n.Sort();
	n.Print();

	// 5, 3, 7 -> 3, 5, 7
}

//Damian Cozma - March 2024
