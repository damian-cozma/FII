#include <iostream>
#include "Math.h"
using namespace std;

int main()
{
	Math x;
	cout << x.Add(3, 4) << endl;
	cout << x.Add(1, 2, 3) << endl;
	cout << x.Add(2.5, 2.6) << endl;
	cout << x.Add(1.1, 2.2, 3.3) << endl;
	cout << x.Mul(3, 4) << endl;
	cout << x.Mul(1, 2, 3) << endl;
	cout << x.Mul(2.5, 2.6) << endl;
	cout << x.Mul(1.1, 2.2, 3.3) << endl;
	cout << x.Add(3, 1, 2, 10) << endl;
	cout << x.Add("Hello ", "World") << endl;
}

//Damian Cozma - March 2024
