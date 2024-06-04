#include <iostream>
using namespace std;

float operator"" _Kelvin(long double a)
{
    return a - 273.15;
}

float operator"" _Fahrenheit(long double a)
{
    return (a - 32) / 1.8;
}

int main() {
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;
    cout << a << ' ' << b << endl;
    return 0;
}
