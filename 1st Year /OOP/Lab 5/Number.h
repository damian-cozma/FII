//UNFINISHED

#define _CRT_SECURE_NO_WARNINGS
#pragma once
class Number
{
	char *value;
	int base;
	int decimal;
public:
	Number(const char* value, int base);
	Number(const int nr); 
	~Number();

	int operator[](int index);
	void operator=(const Number& A);
	void operator=(const int nr);

	friend Number operator+(const Number& A, const Number& B);
	friend Number operator-(const Number& A, const Number& B);
	friend Number operator+=(const Number& A, const Number& B);

	bool operator>(const Number& A);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); 
	int  GetBase(); 
};

// Damian Cozma - March 2024
