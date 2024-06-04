#pragma once

class Number
{
    int base, decimal;
    char * value;
public:
    Number(const char * value, int base); // where base is between 2 and 16
    Number(const char * value);
    Number(int value);
    ~Number();

    char operator[](int index);
    Number(const Number &n);
    Number(Number &&n);
    Number& operator=(Number &&n);
    Number& operator=(const Number &n);
    Number operator+(Number &n);
    Number operator-(Number &n);

    //all operators
    bool operator>(Number &n);
    bool operator<(Number &n);
    bool operator>=(Number &n);
    bool operator<=(Number &n);
    bool operator==(Number &n);
    bool operator!=(Number &n);

    Number& operator--();
    Number operator--(int);
    Number& operator+=(Number &n);
    Number& operator-=(Number &n);

    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base
};

// Damian Cozma - March 2024
