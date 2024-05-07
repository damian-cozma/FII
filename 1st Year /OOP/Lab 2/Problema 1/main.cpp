#include "Numbers.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    Numbers obj;

    obj.Init();
    obj.Add(1);
    obj.Add(10);
    obj.Add(2);

    obj.Print();
    obj.Sort();
    obj.Print();

}
