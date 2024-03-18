#pragma once
class Math
{
public:
    static int Add(int, int);
    static int Add(int, int, int);
    static double Add(double, double); // (1)
    static double Add(double, double, double); // (2)
    static int Mul(int, int);
    static int Mul(int, int, int);
    static double Mul(double, double); // (3)
    static double Mul(double, double, double); // (4)
    static int Add(int count, ...); 
    static char* Add(const char*, const char*);
};

// (1),(2),(3),(4) nu vad sensul sa returneze int,
// am schimbat in double

//Damian Cozma - March 2024
